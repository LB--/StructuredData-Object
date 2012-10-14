#include "Common.h"

#ifndef RUN_ONLY
// PROPERTIES /////////////////////////////////////////////////////////////////

// Property identifiers
enum {
	PROPID_SETTINGS = PROPID_EXTITEM_CUSTOM_FIRST,
	PropVersion,
};


// Property definitions
PropData Properties[] =
{
	PropData_StaticString(PropVersion, (UINT_PTR)"Version", (UINT_PTR)"The current version of the Structured Data object."),
	PropData_End()
};
#endif


int WINAPI DLLExport MakeIconEx ( mv _far *mV, cSurface* pIconSf, LPTSTR lpName, fpObjInfo oiPtr, LPEDATA edPtr )
{
#ifndef RUN_ONLY

	pIconSf->Delete();
	pIconSf->Clone(*SDK->Icon);

	pIconSf->SetTransparentColor(RGB(255, 255, 255));

#endif // !defined(RUN_ONLY)
   return 0;
}

int WINAPI DLLExport CreateObject(mv _far *mV, fpLevObj loPtr, LPEDATA edPtr)
{
#ifndef RUN_ONLY
	if(IS_COMPATIBLE(mV))
	{
		Edif::Init(mV, edPtr);
		return 0;
	}
#endif
	return -1;
}

BOOL WINAPI EditObject (mv _far *mV, fpObjInfo oiPtr, fpLevObj loPtr, LPEDATA edPtr)
{
	return FALSE;
}

void WINAPI	DLLExport PutObject(mv _far *mV, fpLevObj loPtr, LPEDATA edPtr, ushort cpt)
{
}
void WINAPI	DLLExport RemoveObject(mv _far *mV, fpLevObj loPtr, LPEDATA edPtr, ushort cpt)
{
#ifndef RUN_ONLY
	if (0 == cpt)
	{
		Edif::Free(edPtr);
	}
#endif
}

void WINAPI DLLExport DuplicateObject(mv __far *mV, fpObjInfo oiPtr, LPEDATA edPtr)
{
}

void WINAPI DLLExport GetObjectRect(mv _far *mV, RECT FAR *rc, fpLevObj loPtr, LPEDATA edPtr)
{
#ifndef RUN_ONLY
	rc->right = rc->left + SDK->Icon->GetWidth();
	rc->bottom = rc->top + SDK->Icon->GetHeight();
#endif
}

void WINAPI DLLExport EditorDisplay(mv _far *mV, fpObjInfo oiPtr, fpLevObj loPtr, LPEDATA edPtr, RECT FAR *rc)
{
#ifndef RUN_ONLY
	LPSURFACE Surface = WinGetSurface((int) mV->mvIdEditWin);
	if(!Surface) return;
	SDK->Icon->Blit(*Surface, rc->left, rc->top, BMODE_TRANSP, BOP_COPY, 0);
#endif
}

extern "C" BOOL WINAPI DLLExport IsTransparent(mv _far *mV, fpLevObj loPtr, LPEDATA edPtr, int dx, int dy)
{
	return FALSE;
}

void WINAPI	DLLExport PrepareToWriteObject(mv _far *mV, LPEDATA edPtr, fpObjInfo adoi)
{
}

BOOL WINAPI GetFilters(LPMV mV, LPEDATA edPtr, DWORD dwFlags, LPVOID pReserved)
{
	return FALSE;
}

BOOL WINAPI	DLLExport UsesFile(LPMV mV, LPTSTR fileName)
{
	return FALSE;
}

void WINAPI	DLLExport CreateFromFile(LPMV mV, LPTSTR fileName, LPEDATA edPtr)
{
}

// ============================================================================
// PROPERTIES
// ============================================================================

BOOL WINAPI DLLExport GetProperties(LPMV mV, LPEDATA edPtr, BOOL bMasterItem)
{
#ifndef RUN_ONLY
	mvInsertProps(mV, edPtr, Properties, PROPID_TAB_CUSTOM1, TRUE);
#endif
	return TRUE;
}
void WINAPI DLLExport ReleaseProperties(LPMV mV, LPEDATA edPtr, BOOL bMasterItem)
{
}

LPARAM WINAPI DLLExport GetPropCreateParam(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
	return NULL;
}
void WINAPI DLLExport ReleasePropCreateParam(LPMV mV, LPEDATA edPtr, UINT nPropID, LPARAM lParam)
{
}

LPVOID WINAPI DLLExport GetPropValue(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
#ifndef RUN_ONLY
	if(nPropID == PropVersion)
	{
		return new CPropDataValue("Beta 2");
	}
#endif
	return NULL;
}

BOOL WINAPI DLLExport GetPropCheck(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
	return 0;
}

void WINAPI DLLExport SetPropValue(LPMV mV, LPEDATA edPtr, UINT nPropID, LPVOID lParam)
{
}

void WINAPI DLLExport SetPropCheck(LPMV mV, LPEDATA edPtr, UINT nPropID, BOOL nCheck)
{
}

BOOL WINAPI DLLExport EditProp(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
	return FALSE;
}

BOOL WINAPI IsPropEnabled(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
#ifndef RUN_ONLY
	if(nPropID == PropVersion)
	{
		return FALSE;
	}
#endif
	return TRUE;
}


// ===============
// TEXT PROPERTIES
// ===============

DWORD WINAPI DLLExport GetTextCaps(mv _far *mV, LPEDATA edPtr)
{
	return 0;
}

BOOL WINAPI DLLExport GetTextFont(mv _far *mV, LPEDATA edPtr, LPLOGFONT plf, LPTSTR pStyle, UINT cbSize)
{
	return TRUE;
}
BOOL WINAPI DLLExport SetTextFont(mv _far *mV, LPEDATA edPtr, LPLOGFONT plf, LPCSTR pStyle)
{
	return TRUE;
}

COLORREF WINAPI DLLExport GetTextClr(mv _far *mV, LPEDATA edPtr)
{
	return 0;
}
void WINAPI DLLExport SetTextClr(mv _far *mV, LPEDATA edPtr, COLORREF color)
{
}

DWORD WINAPI DLLExport GetTextAlignment(mv _far *mV, LPEDATA edPtr)
{
	return 0;
}
void WINAPI DLLExport SetTextAlignment(mv _far *mV, LPEDATA edPtr, DWORD dwAlignFlags)
{
}


// ----------------------------------------------------------
// Custom Parameters
// ----------------------------------------------------------

void WINAPI InitParameter(mv _far *mV, short code, paramExt* pExt)
{
}

void WINAPI EditParameter(mv _far *mV, short code, paramExt* pExt)
{
}

void WINAPI GetParameterString(mv _far *mV, short code, paramExt* pExt, LPSTR pDest, short size)
{
}
