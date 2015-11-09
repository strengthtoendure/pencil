#ifndef KeyFrame_H
#define KeyFrame_H

#include <cstdint>
#include <QString>
#include "pencilerror.h"


enum class KeyFrameType
{
    NULLTYPE,
    BITMAP_TYPE,
    VECTOR_TYPE,
    CAMERA_TYPE,
    SOUND_TYPE,
};

class KeyFrame
{
public:
    KeyFrame();
    virtual ~KeyFrame();

    int  pos() { return mFrame; }
    void setPos( int position ) { mFrame = position; }
    int  length() { return mLength; }
    void setModified( bool b ) { mIsModified = b; }

    QString fileName() { return mAttachedFileName; }
    void    setFileName( QString strFileName ) { mAttachedFileName = strFileName; }

private:
    int mFrame       = -1;
    int mLength      =  1;
    bool mIsModified = false;
    QString mAttachedFileName;
};

class NullKeyFrame : public KeyFrame
{
public:
    static NullKeyFrame* get();
private:
    NullKeyFrame() {}
    NullKeyFrame( const NullKeyFrame& ) {}
    void operator=( const NullKeyFrame& ) {}
};

#endif // KeyFrame_H
