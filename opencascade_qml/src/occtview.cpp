//#include <windows.h>
//#include <WNT_Window.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <Cocoa_Window.hxx>

#include "occtview.h"

#include <BRepPrimAPI_MakeCone.hxx>
#include <AIS_Shape.hxx>
#include <QWidget>


#ifdef WNT
    #include <WNT_Window.hxx>
#elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
    #include <Cocoa_Window.hxx>
#else
    #undef Bool
    #undef CursorShape
    #undef None
    #undef KeyPress
    #undef KeyRelease
    #undef FocusIn
    #undef FocusOut
    #undef FontChange
    #undef Expose
    #include <Xw_Window.hxx>
#endif


OcctView::OcctView(QQuickItem* parent) :
	QQuickItem(parent)
{
	QObject::connect(this, &QQuickItem::windowChanged, this, &OcctView::onWindowChanged, Qt::DirectConnection);
}

void OcctView::onWindowChanged(QQuickWindow* window)
{
	if (!window)
		return;

	QObject::connect(window, &QQuickWindow::beforeSynchronizing, this, &OcctView::onSynchronizing, Qt::DirectConnection);
	QObject::connect(window, &QQuickWindow::sceneGraphInvalidated, this, &OcctView::onInvalidating, Qt::DirectConnection);

	window->setClearBeforeRendering(false);
}

void OcctView::onSynchronizing()
{
	// If the viewer is not yet initialized, initialize it.
	if (m_viewer.IsNull())
	{
		this->initializeViewer(Aspect_Drawable(this->window()->winId()));
		QObject::connect(this->window(), &QQuickWindow::beforeRendering, this, &OcctView::onRendering, Qt::DirectConnection);
	}

	// Get the control position and size.
	QPoint viewportPos = this->mapToGlobal(QPointF(0, 0)).toPoint();
	QSize viewportSize = this->size().toSize();

	// Check if the viewport needs to be resized.
	if (viewportPos.x() != m_viewportPos.x() || viewportPos.y() != m_viewportPos.y())
		m_view->MustBeResized();
	if (viewportSize.width() != m_viewportSize.width() || viewportSize.height() != m_viewportSize.height())
	{
		m_view->MustBeResized();
		m_view->Invalidate();
	}

	// Store the current pos and size.
	m_viewportPos = viewportPos;
	m_viewportSize = viewportSize;
}

void OcctView::onInvalidating()
{
	m_view.Nullify();
	m_context.Nullify();
	m_viewer.Nullify();
}

void OcctView::onRendering()
{
	if (m_view.IsNull())
		return;

	m_mutex.lock();
	// TODO: Handle user input.
	m_mutex.unlock();

	// Redraw the view.
	// NOTE: MustBeResized is called here, due to a bug that causes the background to
	//       go white, when hovering a MenuBar (and possibly other top-level QML items).
	m_view->Redraw();
	m_view->MustBeResized();
}

static Handle(Graphic3d_GraphicDriver)& GetGraphicDriver()
{
  static Handle(Graphic3d_GraphicDriver) aGraphicDriver;
  return aGraphicDriver;
}

void OcctView::initializeViewer(const Aspect_Drawable& drawable)
{
	Q_ASSERT(m_viewer.IsNull());

    // Create Aspect_DisplayConnection
    Handle(Aspect_DisplayConnection) aDisplayConnection =
            new Aspect_DisplayConnection();

    // Get graphic driver if it exists, otherwise initialise it
    if (GetGraphicDriver().IsNull())
    {
        GetGraphicDriver() = new OpenGl_GraphicDriver(aDisplayConnection);
    }

    // Get window handle. This returns something suitable for all platforms.        
    WId window_handle = (WId) window()->winId();

    // Create appropriate window for platform
    #ifdef WNT
        Handle(WNT_Window) wind = new WNT_Window((Aspect_Handle) window_handle);
    #elif defined(__APPLE__) && !defined(MACOSX_USE_GLX)
        Handle(Cocoa_Window) wind = new Cocoa_Window((NSView *) window_handle);
    #else
        Handle(Xw_Window) wind = new Xw_Window(aDisplayConnection, (Window) window_handle);
    #endif

    // Create V3dViewer and V3d_View
    m_viewer = new V3d_Viewer(GetGraphicDriver(), Standard_ExtString("viewer3d"));

	// Create and setup the viewer.    
	m_viewer->SetDefaultBackgroundColor(Quantity_NOC_GRAY50);
	m_viewer->SetDefaultLights();
	m_viewer->SetLightOn();

	// Create and setup interactivity context.
	m_context = new AIS_InteractiveContext(m_viewer);
	m_context->SetDisplayMode(AIS_Shaded, false);

	// Create and setup view.
    Handle(Cocoa_Window) window = new Cocoa_Window("drawable", 0, 0, 600, 400);   

    // Create V3dViewer and V3d_View
    m_view = m_viewer->CreateView();

    m_view->SetWindow(wind);
    if (!wind->IsMapped()) wind->Map();

    // Create AISInteractiveContext
    m_context = new AIS_InteractiveContext(m_viewer);

    // Set up lights etc
    m_viewer->SetDefaultLights();
    m_viewer->SetLightOn();

    m_view->SetBackgroundColor(Quantity_NOC_BLACK);
    m_view->MustBeResized();
    m_view->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_ZBUFFER);

    m_context->SetDisplayMode(AIS_Shaded, Standard_True);

	// Create a demo scene.
	this->createDemoScene();
}

void OcctView::createDemoScene()
{
	// Create a bisque cone at [0, 10, 0].
	gp_Ax2 axis;
	axis.SetLocation(gp_Pnt(0.0, 10.0, 0.0));

	TopoDS_Shape bisqueCone = BRepPrimAPI_MakeCone(axis, 3.0, 1.5, 5.0).Shape();
	Handle(AIS_Shape) bisqueConeShape = new AIS_Shape(bisqueCone);
	bisqueConeShape->SetColor(Quantity_NOC_BISQUE);

	// Create a chocolate cone at [8, 10, 0].
	axis.SetLocation(gp_Pnt(8.0, 10.0, 0.0));
	TopoDS_Shape chocoCone = BRepPrimAPI_MakeCone(axis, 3.0, 0.0, 5.0).Shape();
	Handle(AIS_Shape) chocoConeShape = new AIS_Shape(chocoCone);
	chocoConeShape->SetColor(Quantity_NOC_CHOCOLATE);

	m_context->Display(bisqueConeShape, Standard_True);
	m_context->Display(chocoConeShape, Standard_True);

	// Fit all into the view.
	m_view->FitAll();
}
