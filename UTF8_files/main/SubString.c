/*
    UTF8.library
    Copyright (C) 2014-2020  Kjetil Hvalstrand

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
    USA
*/


#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <libraries/UTF8.h>
#include <proto/UTF8.h>
#include <stdarg.h>
#include "../libbase.h"
#include "../UTF8_vectors.h"

/****** UTF8/main/Encode ******************************************
*
*   NAME
*      Encode -- Description
*
*   SYNOPSIS
*       unsigned char * _UTF8_SubString( unsigned char *UTF8, int _start, int _len, ULONG flags )
*
*   FUNCTION
*
*   INPUTS
*       start - 
*       len - 
*
*   RESULT
*       The result ...
*
*   EXAMPLE
*
*   NOTES
*
*   BUGS
*
*   SEE ALSO
*
*****************************************************************************
*
*/


unsigned char * _UTF8_SubString(struct UTF8IFace *Self,
		unsigned char *UTF8, int _start, int _len, ULONG mem_flags )
{
//	struct _Library *libBase = (struct _Library *) Self -> Data.LibBase;
	int pos, size;
	unsigned char *ret;

	pos = _UTF8_GetOffsetSize( Self, UTF8, _start);
	if (pos == -1) return NULL;

	size = _UTF8_GetOffsetSize( Self, UTF8+pos,_len) ;
	if (size == -1) return NULL;

	ret = (unsigned char *) AllocVecTags( size+1 , AVT_Type, mem_flags, TAG_END);
	if (ret)
	{
		CopyMem(UTF8+pos,ret,size);
		ret[size] = 0;
	}

	return ret;
}

