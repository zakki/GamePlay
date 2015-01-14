#ifndef HMD_H_
#define HMD_H_

#include "Vector2.h"
#include "Vector3.h"
#include "Matrix.h"
#include "Rectangle.h"

namespace gameplay {

class Platform;
class FrameBuffer;

class HMD
{
    friend class Platform;
    friend class Game;
public:
    HMD();

    const Rectangle& getViewport(unsigned int index) const;
    void getProjection(Matrix* outValue) const;

    void getHeadPosition(unsigned int index, Vector3* outValue) const;
    void getHeadOrientation(unsigned int index, Matrix* outValue) const;

    FrameBuffer* getFrameBuffer(unsigned int index) const;
private:
    virtual ~HMD();

    void setViewport(unsigned int index, const Rectangle& value);
    void setProjection(const Matrix& value);

    void setHeadPosition(unsigned int index, const Vector3& value);
    void setHeadOrientation(unsigned int index, const Matrix& value);

    void setFrameBuffer(unsigned int index, FrameBuffer* value);
 
    static void setHMD(HMD* hmd);
    static HMD* getHMD();

    Rectangle _viewport[2];
    Matrix _projection;
    Vector3 _headPosition[2];
    Matrix _headOrientation[2];
    FrameBuffer* _frameBuffer[2];
};
}
#endif

