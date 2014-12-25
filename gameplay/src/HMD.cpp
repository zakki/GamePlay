#include "Base.h"
#include "HMD.h"

#ifdef WIN32
    #include <windows.h>
    #include <stdio.h>
    #include <direct.h>
#endif

#include "OVR.h"
#include "OVR_Kernel.h"
#include "OVR_CAPI.h"
#include "OVR_CAPI_GL.h"
#include "OVR_Stereo.h"

namespace gameplay
{

HMD* _hmd = NULL;

HMD::HMD()
{
}

HMD::~HMD()
{
}

void HMD::setHMD(HMD* hmd)
{
    _hmd = hmd;
}

HMD* HMD::getHMD()
{
    return _hmd;
}

void HMD::setViewport(unsigned int index, const Rectangle& viewport)
{
    _viewport[index] = viewport;
}

const Rectangle& HMD::getViewport(unsigned int index) const
{
    return _viewport[index];
}

void HMD::getProjection(Matrix* outValue) const
{
	outValue->set(_projection);
}

void HMD::getHeadPosition(unsigned int index, Vector3* outValue) const
{
	outValue->set(_headPosition[index]);
}

void HMD::getHeadOrientation(unsigned int index, Matrix* outValue) const
{
	outValue->set(_headOrientation[index]);
}

void HMD::setProjection(const Matrix& value)
{
	_projection.set(value);
}

void HMD::setHeadPosition(unsigned int index, const Vector3& value)
{
	_headPosition[index].set(value);
}

void HMD::setHeadOrientation(unsigned int index, const Matrix& value)
{
	_headOrientation[index].set(value);
}

}
