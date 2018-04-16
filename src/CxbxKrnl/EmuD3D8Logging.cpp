// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;;
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->EmuD3D8Logging.cpp
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2017 Patrick van Logchem <pvanlogchem@gmail.com>
// *
// *  All rights reserved
// *
// ******************************************************************
#define _XBOXKRNL_DEFEXTRN_

#include "Logging.h"
#include "EmuD3D8Logging.h"

#ifdef _DEBUG

// prevent name collisions
namespace XTL
{

//
// Host D3D LOGRENDER(Type) implementations
//

ENUM2STR_START(D3DCUBEMAP_FACES)
	ENUM2STR_CASE(D3DCUBEMAP_FACE_POSITIVE_X)
	ENUM2STR_CASE(D3DCUBEMAP_FACE_NEGATIVE_X)
	ENUM2STR_CASE(D3DCUBEMAP_FACE_POSITIVE_Y)
	ENUM2STR_CASE(D3DCUBEMAP_FACE_NEGATIVE_Y)
	ENUM2STR_CASE(D3DCUBEMAP_FACE_POSITIVE_Z)
	ENUM2STR_CASE(D3DCUBEMAP_FACE_NEGATIVE_Z)
ENUM2STR_END_and_LOGRENDER(D3DCUBEMAP_FACES)

ENUM2STR_START(D3DFORMAT)
	ENUM2STR_CASE(D3DFMT_UNKNOWN) // = 0,
	ENUM2STR_CASE(D3DFMT_R8G8B8) // = 20,
	ENUM2STR_CASE(D3DFMT_A8R8G8B8) // = 21,
	ENUM2STR_CASE(D3DFMT_X8R8G8B8) // = 22,
	ENUM2STR_CASE(D3DFMT_R5G6B5) // = 23,
	ENUM2STR_CASE(D3DFMT_X1R5G5B5) // = 24,
	ENUM2STR_CASE(D3DFMT_A1R5G5B5) // = 25,
	ENUM2STR_CASE(D3DFMT_A4R4G4B4) // = 26,
	ENUM2STR_CASE(D3DFMT_R3G3B2) // = 27,
	ENUM2STR_CASE(D3DFMT_A8) // = 28,
	ENUM2STR_CASE(D3DFMT_A8R3G3B2) // = 29,
	ENUM2STR_CASE(D3DFMT_X4R4G4B4) // = 30,
	ENUM2STR_CASE(D3DFMT_A2B10G10R10) // = 31,
#ifdef CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_A8B8G8R8) // = 32,
	ENUM2STR_CASE(D3DFMT_X8B8G8R8) // = 33,
#endif // CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_G16R16) // = 34,
#ifdef CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_A2R10G10B10) // = 35,
	ENUM2STR_CASE(D3DFMT_A16B16G16R16) // = 36,
#endif // CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_A8P8) // = 40,
	ENUM2STR_CASE(D3DFMT_P8) // = 41,
	ENUM2STR_CASE(D3DFMT_L8) // = 50,
	ENUM2STR_CASE(D3DFMT_A8L8) // = 51,
	ENUM2STR_CASE(D3DFMT_A4L4) // = 52,
	ENUM2STR_CASE(D3DFMT_V8U8) // = 60,
	ENUM2STR_CASE(D3DFMT_L6V5U5) // = 61,
	ENUM2STR_CASE(D3DFMT_X8L8V8U8) // = 62,
	ENUM2STR_CASE(D3DFMT_Q8W8V8U8) // = 63,
	ENUM2STR_CASE(D3DFMT_V16U16) // = 64,
#ifndef CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_W11V11U10) // = 65,
#else // !CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_A2W10V10U10) // = 67,
#endif // CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_UYVY) // = MAKEFOURCC('U', 'Y', 'V', 'Y'),
#ifdef CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_R8G8_B8G8) // = MAKEFOURCC('R', 'G', 'B', 'G'),
#endif // CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_YUY2) // = MAKEFOURCC('Y', 'U', 'Y', '2'),
#ifdef CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_G8R8_G8B8) // = MAKEFOURCC('G', 'R', 'G', 'B'),
#endif // CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_DXT1) // = MAKEFOURCC('D', 'X', 'T', '1'),
	ENUM2STR_CASE(D3DFMT_DXT2) // = MAKEFOURCC('D', 'X', 'T', '2'),
	ENUM2STR_CASE(D3DFMT_DXT3) // = MAKEFOURCC('D', 'X', 'T', '3'),
	ENUM2STR_CASE(D3DFMT_DXT4) // = MAKEFOURCC('D', 'X', 'T', '4'),
	ENUM2STR_CASE(D3DFMT_DXT5) // = MAKEFOURCC('D', 'X', 'T', '5'),
	ENUM2STR_CASE(D3DFMT_D16_LOCKABLE) // = 70,
	ENUM2STR_CASE(D3DFMT_D32) // = 71,
	ENUM2STR_CASE(D3DFMT_D15S1) // = 73,
	ENUM2STR_CASE(D3DFMT_D24S8) // = 75,
	ENUM2STR_CASE(D3DFMT_D24X8) // = 77,
	ENUM2STR_CASE(D3DFMT_D24X4S4) // = 79,
	ENUM2STR_CASE(D3DFMT_D16) // = 80,
#ifdef CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_D32F_LOCKABLE) // = 82,
	ENUM2STR_CASE(D3DFMT_D24FS8) // = 83,
#if !defined(D3D_DISABLE_9EX)
	ENUM2STR_CASE(D3DFMT_D32_LOCKABLE) // = 84,
	ENUM2STR_CASE(D3DFMT_S8_LOCKABLE) // = 85,
#endif // !D3D_DISABLE_9EX
	ENUM2STR_CASE(D3DFMT_L16) // = 81,
#endif // CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_VERTEXDATA) // = 100,
	ENUM2STR_CASE(D3DFMT_INDEX16) // = 101,
	ENUM2STR_CASE(D3DFMT_INDEX32) // = 102,
#ifdef CXBX_USE_D3D9
	ENUM2STR_CASE(D3DFMT_Q16W16V16U16) // = 110,
	ENUM2STR_CASE(D3DFMT_MULTI2_ARGB8) // = MAKEFOURCC('M', 'E', 'T', '1'),
	ENUM2STR_CASE(D3DFMT_R16F) // = 111,
	ENUM2STR_CASE(D3DFMT_G16R16F) // = 112,
	ENUM2STR_CASE(D3DFMT_A16B16G16R16F) // = 113,
	ENUM2STR_CASE(D3DFMT_R32F) // = 114,
	ENUM2STR_CASE(D3DFMT_G32R32F) // = 115,
	ENUM2STR_CASE(D3DFMT_A32B32G32R32F) // = 116,
	ENUM2STR_CASE(D3DFMT_CxV8U8) // = 117,
#if !defined(D3D_DISABLE_9EX)
	ENUM2STR_CASE(D3DFMT_A1) // = 118,
	ENUM2STR_CASE(D3DFMT_A2B10G10R10_XR_BIAS) // = 119,
	ENUM2STR_CASE(D3DFMT_BINARYBUFFER) // = 199,
#endif // !D3D_DISABLE_9EX
#endif // CXBX_USE_D3D9
ENUM2STR_END_and_LOGRENDER(D3DFORMAT)

ENUM2STR_START(D3DPOOL)
	ENUM2STR_CASE(D3DPOOL_DEFAULT)
	ENUM2STR_CASE(D3DPOOL_MANAGED)
	ENUM2STR_CASE(D3DPOOL_SYSTEMMEM)
ENUM2STR_END_and_LOGRENDER(D3DPOOL)


//
// Host D3D LOGRENDER(Type) implementations
//

LOGRENDER(D3DLOCKED_RECT)
{
	return os
		LOGRENDER_MEMBER(Pitch)
		LOGRENDER_MEMBER(pBits);
}

LOGRENDER(RECT)
{
	return os
		LOGRENDER_MEMBER(left)
		LOGRENDER_MEMBER(top)
		LOGRENDER_MEMBER(right)
		LOGRENDER_MEMBER(bottom);
}


//
// Cxbx D3D LOGRENDER(Type) implementations
//

ENUM2STR_START(X_D3DCOMMON_TYPE) // Use unshifted values
	ENUM2STR_CASE(X_D3DCOMMON_TYPE_VERTEXBUFFER)
	ENUM2STR_CASE(X_D3DCOMMON_TYPE_INDEXBUFFER)
	ENUM2STR_CASE(X_D3DCOMMON_TYPE_PUSHBUFFER)
	ENUM2STR_CASE(X_D3DCOMMON_TYPE_PALETTE)
	ENUM2STR_CASE(X_D3DCOMMON_TYPE_TEXTURE)
	ENUM2STR_CASE(X_D3DCOMMON_TYPE_SURFACE)
	ENUM2STR_CASE(X_D3DCOMMON_TYPE_FIXUP)
ENUM2STR_END_and_LOGRENDER(X_D3DCOMMON_TYPE)

LOGRENDER(X_D3DRESOURCE_COMMON)
{	
	return os << (DWORD)value << " :"
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" RefCount", int, value & X_D3DCOMMON_REFCOUNT_MASK)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" Type", X_D3DCOMMON_TYPE, value & X_D3DCOMMON_TYPE_MASK) // Don't >> X_D3DCOMMON_TYPE_SHIFT, see ENUM2STR_START(X_D3DCOMMON_TYPE)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" IntRefCount", int, (value & X_D3DCOMMON_INTREFCOUNT_MASK) >> X_D3DCOMMON_INTREFCOUNT_SHIFT)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" ?D3DCreated", bool, (value & X_D3DCOMMON_D3DCREATED) > 0)
		//LOGRENDER_MEMBER_NAME_TYPE_VALUE(" ?IsLocked", bool, value & X_D3DCOMMON_ISLOCKED)
		//LOGRENDER_MEMBER_NAME_TYPE_VALUE(" ?VideoMemory", bool, value & X_D3DCOMMON_VIDEOMEMORY)
		;
}

LOGRENDER(X_D3DRESOURCE_FORMAT)
{
	return os << (DWORD)value << " :"
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" ?Cubemap", bool, (value & X_D3DFORMAT_CUBEMAP) > 0)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" ?BorderColor", bool, (value & X_D3DFORMAT_BORDERSOURCE_COLOR) > 0)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" #Dimensions", int, (value & X_D3DFORMAT_DIMENSION_MASK) >> X_D3DFORMAT_DIMENSION_SHIFT)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" D3DFormat", X_D3DFORMAT, (value & X_D3DFORMAT_FORMAT_MASK) >> X_D3DFORMAT_FORMAT_SHIFT)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" #MipMaps", int, (value & X_D3DFORMAT_MIPMAP_MASK) >> X_D3DFORMAT_MIPMAP_SHIFT)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" USize", int, (value & X_D3DFORMAT_USIZE_MASK) >> X_D3DFORMAT_USIZE_SHIFT)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" VSize", int, (value & X_D3DFORMAT_VSIZE_MASK) >> X_D3DFORMAT_VSIZE_SHIFT)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" PSize", int, (value & X_D3DFORMAT_PSIZE_MASK) >> X_D3DFORMAT_PSIZE_SHIFT);
}

LOGRENDER(X_D3DRESOURCE_SIZE)
{
	return os << (DWORD)value << " :"
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" Width", int, value & X_D3DSIZE_WIDTH_MASK)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" Height", int, (value & X_D3DSIZE_HEIGHT_MASK) >> X_D3DSIZE_HEIGHT_SHIFT)
		LOGRENDER_MEMBER_NAME_TYPE_VALUE(" Pitch", int, (value & X_D3DSIZE_HEIGHT_MASK) >> X_D3DSIZE_PITCH_SHIFT);
}

//
// Xbox D3D LOGRENDER(Type) implementations
//

ENUM2STR_START(X_D3DCULL)
	ENUM2STR_CASE(X_D3DCULL_NONE)
	ENUM2STR_CASE(X_D3DCULL_CW)
	ENUM2STR_CASE(X_D3DCULL_CCW)
ENUM2STR_END_and_LOGRENDER(X_D3DCULL)

ENUM2STR_START(X_D3DFORMAT)
	ENUM2STR_CASE(X_D3DFMT_L8)
	ENUM2STR_CASE(X_D3DFMT_AL8)
	ENUM2STR_CASE(X_D3DFMT_A1R5G5B5)
	ENUM2STR_CASE(X_D3DFMT_X1R5G5B5)
	ENUM2STR_CASE(X_D3DFMT_A4R4G4B4)
	ENUM2STR_CASE(X_D3DFMT_R5G6B5)
	ENUM2STR_CASE(X_D3DFMT_A8R8G8B8)
	ENUM2STR_CASE(X_D3DFMT_X8R8G8B8) // X_D3DFMT_X8L8V8U8 = 0x07, // Alias
	ENUM2STR_CASE(X_D3DFMT_P8)
	ENUM2STR_CASE(X_D3DFMT_A8)
	ENUM2STR_CASE(X_D3DFMT_A8L8)
	ENUM2STR_CASE(X_D3DFMT_R6G5B5) // X_D3DFMT_L6V5U5 = 0x27, // Alias
	ENUM2STR_CASE(X_D3DFMT_G8B8) // X_D3DFMT_V8U8 = 0x28, // Alias
	ENUM2STR_CASE(X_D3DFMT_R8B8)
	ENUM2STR_CASE(X_D3DFMT_D24S8)
	ENUM2STR_CASE(X_D3DFMT_F24S8)
	ENUM2STR_CASE(X_D3DFMT_D16) // X_D3DFMT_D16_LOCKABLE = 0x2c, // Alias
	ENUM2STR_CASE(X_D3DFMT_F16)
	ENUM2STR_CASE(X_D3DFMT_L16)
	ENUM2STR_CASE(X_D3DFMT_V16U16)
	ENUM2STR_CASE(X_D3DFMT_R5G5B5A1)
	ENUM2STR_CASE(X_D3DFMT_R4G4B4A4)
	ENUM2STR_CASE(X_D3DFMT_A8B8G8R8) // X_D3DFMT_Q8W8V8U8 = 0x3A, // Alias
	ENUM2STR_CASE(X_D3DFMT_B8G8R8A8)
	ENUM2STR_CASE(X_D3DFMT_R8G8B8A8)
	ENUM2STR_CASE(X_D3DFMT_YUY2)
	ENUM2STR_CASE(X_D3DFMT_UYVY)
	ENUM2STR_CASE(X_D3DFMT_DXT1)
	ENUM2STR_CASE(X_D3DFMT_DXT3) // X_D3DFMT_DXT2 = 0x0E, // Alias for X_D3DFMT_DXT3
	ENUM2STR_CASE(X_D3DFMT_DXT5) // X_D3DFMT_DXT4 = 0x0F, // Alias for X_D3DFMT_DXT5
	ENUM2STR_CASE(X_D3DFMT_LIN_A1R5G5B5)
	ENUM2STR_CASE(X_D3DFMT_LIN_R5G6B5)
	ENUM2STR_CASE(X_D3DFMT_LIN_A8R8G8B8)
	ENUM2STR_CASE(X_D3DFMT_LIN_L8)
	ENUM2STR_CASE(X_D3DFMT_LIN_R8B8)
	ENUM2STR_CASE(X_D3DFMT_LIN_G8B8) // X_D3DFMT_LIN_V8U8 = 0x17, // Alias
	ENUM2STR_CASE(X_D3DFMT_LIN_AL8)
	ENUM2STR_CASE(X_D3DFMT_LIN_X1R5G5B5)
	ENUM2STR_CASE(X_D3DFMT_LIN_A4R4G4B4)
	ENUM2STR_CASE(X_D3DFMT_LIN_X8R8G8B8) // X_D3DFMT_LIN_X8L8V8U8 = 0x1e, // Alias
	ENUM2STR_CASE(X_D3DFMT_LIN_A8)
	ENUM2STR_CASE(X_D3DFMT_LIN_A8L8)
	ENUM2STR_CASE(X_D3DFMT_LIN_D24S8)
	ENUM2STR_CASE(X_D3DFMT_LIN_F24S8)
	ENUM2STR_CASE(X_D3DFMT_LIN_D16)
	ENUM2STR_CASE(X_D3DFMT_LIN_F16)
	ENUM2STR_CASE(X_D3DFMT_LIN_L16)
	ENUM2STR_CASE(X_D3DFMT_LIN_V16U16)
	ENUM2STR_CASE(X_D3DFMT_LIN_R6G5B5) // X_D3DFMT_LIN_L6V5U5 = 0x37, // Alias
	ENUM2STR_CASE(X_D3DFMT_LIN_R5G5B5A1)
	ENUM2STR_CASE(X_D3DFMT_LIN_R4G4B4A4)
	ENUM2STR_CASE(X_D3DFMT_LIN_A8B8G8R8)
	ENUM2STR_CASE(X_D3DFMT_LIN_B8G8R8A8)
	ENUM2STR_CASE(X_D3DFMT_LIN_R8G8B8A8)
	ENUM2STR_CASE(X_D3DFMT_VERTEXDATA)
	ENUM2STR_CASE(X_D3DFMT_INDEX16) // Dxbx addition : Not an Xbox format, used internally
	ENUM2STR_CASE(X_D3DFMT_UNKNOWN) // Unique declaration to make overloads possible
ENUM2STR_END_and_LOGRENDER(X_D3DFORMAT)

ENUM2STR_START(X_D3DPRIMITIVETYPE)
	ENUM2STR_CASE(X_D3DPT_POINTLIST)
	ENUM2STR_CASE(X_D3DPT_LINELIST)
	ENUM2STR_CASE(X_D3DPT_LINELOOP)
	ENUM2STR_CASE(X_D3DPT_LINESTRIP)
	ENUM2STR_CASE(X_D3DPT_TRIANGLELIST)
	ENUM2STR_CASE(X_D3DPT_TRIANGLESTRIP)
	ENUM2STR_CASE(X_D3DPT_TRIANGLEFAN)
	ENUM2STR_CASE(X_D3DPT_QUADLIST)
	ENUM2STR_CASE(X_D3DPT_QUADSTRIP)
	ENUM2STR_CASE(X_D3DPT_POLYGON)
ENUM2STR_END_and_LOGRENDER(X_D3DPRIMITIVETYPE)

ENUM2STR_START(X_D3DRESOURCETYPE)
	ENUM2STR_CASE(X_D3DRTYPE_NONE)
	ENUM2STR_CASE(X_D3DRTYPE_SURFACE)
	ENUM2STR_CASE(X_D3DRTYPE_VOLUME)
	ENUM2STR_CASE(X_D3DRTYPE_TEXTURE)
	ENUM2STR_CASE(X_D3DRTYPE_VOLUMETEXTURE)
	ENUM2STR_CASE(X_D3DRTYPE_CUBETEXTURE)
	ENUM2STR_CASE(X_D3DRTYPE_VERTEXBUFFER)
	ENUM2STR_CASE(X_D3DRTYPE_INDEXBUFFER)
	ENUM2STR_CASE(X_D3DRTYPE_PUSHBUFFER)
	ENUM2STR_CASE(X_D3DRTYPE_PALETTE)
	ENUM2STR_CASE(X_D3DRTYPE_FIXUP)
ENUM2STR_END_and_LOGRENDER(X_D3DRESOURCETYPE)

ENUM2STR_START(X_D3DSET_DEPTH_CLIP_PLANES_FLAGS)
	ENUM2STR_CASE(X_D3DSDCP_SET_VERTEXPROGRAM_PLANES)
	ENUM2STR_CASE(X_D3DSDCP_SET_FIXEDFUNCTION_PLANES)
	ENUM2STR_CASE(X_D3DSDCP_USE_DEFAULT_VERTEXPROGRAM_PLANES)
	ENUM2STR_CASE(X_D3DSDCP_USE_DEFAULT_FIXEDFUNCTION_PLANES)
ENUM2STR_END_and_LOGRENDER(X_D3DSET_DEPTH_CLIP_PLANES_FLAGS)

FLAGS2STR_START(X_D3DUSAGE)
	FLAG2STR(X_D3DUSAGE_RENDERTARGET)
	FLAG2STR(X_D3DUSAGE_DEPTHSTENCIL)
	FLAG2STR(X_D3DUSAGE_WRITEONLY)
	FLAG2STR(X_D3DUSAGE_POINTS)
	FLAG2STR(X_D3DUSAGE_RTPATCHES)
	FLAG2STR(X_D3DUSAGE_DYNAMIC)
	FLAG2STR(X_D3DUSAGE_PERSISTENTDIFFUSE)
	FLAG2STR(X_D3DUSAGE_PERSISTENTSPECULAR)
	FLAG2STR(X_D3DUSAGE_PERSISTENTBACKDIFFUSE)
	FLAG2STR(X_D3DUSAGE_PERSISTENTBACKSPECULAR)
	//#define X_D3DUSAGE_BORDERSOURCE_COLOR     0x00000000L   // Xbox-only
	FLAG2STR(X_D3DUSAGE_BORDERSOURCE_TEXTURE)
FLAGS2STR_END_and_LOGRENDER(X_D3DUSAGE)

LOGRENDER(X_D3DDISPLAYMODE)
{
	return os
		LOGRENDER_MEMBER(Width)
		LOGRENDER_MEMBER(Height)
		LOGRENDER_MEMBER(RefreshRate)
		LOGRENDER_MEMBER(Flags)
		LOGRENDER_MEMBER(Format);
}

LOGRENDER(X_D3DVIEWPORT8)
{
	return os
		LOGRENDER_MEMBER(X)
		LOGRENDER_MEMBER(Y)
		LOGRENDER_MEMBER(Width)
		LOGRENDER_MEMBER(Height)
		LOGRENDER_MEMBER(MinZ)
		LOGRENDER_MEMBER(MaxZ);
}

LOGRENDER(X_D3DResource)
{
// TODO : Get more specific logging compiling
//	if ((value.Common & X_D3DCOMMON_TYPE_MASK) == X_D3DCOMMON_TYPE_TEXTURE)
//		return os << (X_D3DPixelContainer)&value;

	return os
		LOGRENDER_MEMBER_TYPE(X_D3DRESOURCE_COMMON, Common)
		LOGRENDER_MEMBER(Data)
		LOGRENDER_MEMBER(Lock);
}

LOGRENDER(X_D3DPixelContainer)
{
	return os
		LOGRENDER_MEMBER_TYPE(X_D3DRESOURCE_COMMON, Common)
		LOGRENDER_MEMBER(Data)
		LOGRENDER_MEMBER(Lock)
		//
		LOGRENDER_MEMBER_TYPE(X_D3DRESOURCE_FORMAT, Format)
		LOGRENDER_MEMBER_TYPE(X_D3DRESOURCE_SIZE, Size);
}

}; // end of namespace XTL

#endif