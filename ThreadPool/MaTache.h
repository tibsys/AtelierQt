#ifndef MATACHE_H
#define MATACHE_H

#include <QRunnable>

class MaTache : public QRunnable
{
public:
    explicit MaTache();
    virtual void run();
    
};

#endif // MATACHE_H
