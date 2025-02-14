/* Copyright (C) 2022-2025 Stefan-Mihai MOGA
This file is part of IntelliFile application developed by Stefan-Mihai MOGA.
IntelliFile is an alternative Windows version to the famous Total Commander!

IntelliFile is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Open
Source Initiative, either version 3 of the License, or any later version.

IntelliFile is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
IntelliFile. If not, see <http://www.opensource.org/licenses/gpl-3.0.html>*/

// ViewTextFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IntelliFile.h"
#include "ViewTextFileDlg.h"

// CViewTextFileDlg dialog

IMPLEMENT_DYNAMIC(CViewTextFileDlg, CDialogEx)

const TCHAR* g_cmakeKeywords
{
	/* https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html */
	_T("block break cmake_host_system_information cmake_language cmake_minimum_required ")
	_T("cmake_parse_arguments cmake_path cmake_policy configure_file continue ")
	_T("else elseif endblock endforeach endfunction endif endmacro endwhile ")
	_T("execute_process file find_file find_library find_package find_path ")
	_T("find_program foreach function get_cmake_property get_directory_property ")
	_T("get_filename_component get_property if include include_guard list macro ")
	_T("mark_as_advanced math message option return separate_arguments set ")
	_T("set_directory_properties set_property site_name string unset variable_watch while ")
	// Project
	_T("add_compile_definitions add_compile_options add_custom_command add_custom_target ")
	_T("add_definitions add_dependencies add_executable add_library add_link_options ")
	_T("add_subdirectory add_test aux_source_directory build_command cmake_file_api ")
	_T("create_test_sourcelist define_property enable_language enable_testing export ")
	_T("fltk_wrap_ui get_source_file_property get_target_property get_test_property ")
	_T("include_directories include_external_msproject include_regular_expression ")
	_T("install link_directories link_libraries load_cache project remove_definitions ")
	_T("set_source_files_properties set_target_properties set_tests_properties ")
	_T("source_group target_compile_definitions target_compile_features ")
	_T("target_compile_options target_include_directories target_link_directories ")
	_T("target_link_libraries target_link_options target_precompile_headers ")
	_T("target_sources try_compile try_run ctest_build ctest_configure ctest_coverage ")
	_T("ctest_empty_binary_directory ctest_memcheck ctest_read_custom_files ctest_run_script ")
	_T("ctest_sleep ctest_start ctest_submit ctest_test ctest_update ctest_upload")
};

const TCHAR* g_cppKeywords
{
	/* _T("alignas alignof and and_eq asm atomic_cancel atomic_commit atomic_noexcept auto bitand bitor bool break ")
	_T("case catch char char8_t char16_t char32_t class compl concept const consteval constexpr constinit const_cast continue ")
	_T("co_await co_return co_yield decltype default delete do double dynamic_cast else enum explicit export extern false float for ")
	_T("friend goto if inline int long mutable namespace new noexcept not not_eq nullptr ")
	_T("operator or or_eq private protected public ")
	_T("reflexpr register reinterpret_cast requires return short signed sizeof static static_assert static_cast struct switch synchronized ")
	_T("template this thread_local throw true try typedef typeid typename union unsigned using ")
	_T("virtual void volatile wchar_t while xor xor_eq") */

	/* https://www.w3schools.com/cpp/cpp_ref_keywords.asp */
	_T("and and_eq bitand bitor bool break case catch char class compl const ")
	_T("continue default delete do double else enum false float for friend goto ")
	_T("if int long namespace new not not_eq or or_eq private protected public ")
	_T("return short signed sizeof static struct switch template this throw true ")
	_T("try typedef unsigned using virtual void while xor xor_eq")
};

const TCHAR* g_csKeywords
{
	_T("abstract as base bool break byte case catch char checked class const ")
	_T("continue decimal default delegate do double else enum event explicit ")
	_T("extern false finally fixed float for foreach goto if implicit in int ")
	_T("interface internal is lock long namespace new null object operator ")
	_T("out override params private protected public readonly ref return sbyte ")
	_T("sealed short sizeof stackalloc static string struct switch this throw ")
	_T("true try typeof uint ulong unchecked unsafe ushort using virtual void ")
	_T("volatile while")
};

const TCHAR* g_groovyKeywords
{
	/* https://docs.oracle.com/cloud/latest/big-data-discovery-cloud/BDDDE/rsu_transform_unsupported_features.htm */
	_T("abstract as assert boolean break byte case catch char class const ")
	_T("continue def default do double else enum extends false final finally ")
	_T("float for goto if implements import in instanceof int interface long ")
	_T("native new null package private protected public return short static ")
	_T("strictfp super switch synchronized this threadsafe throw throws ")
	_T("transient true try void volatile while")
};

const TCHAR* g_javaKeywords
{
	/* https://www.w3schools.com/java/java_ref_keywords.asp */
	_T("abstract assert boolean break byte case catch char class continue const ")
	_T("default do double else enum exports extends final finally float for goto ")
	_T("if implements import instanceof int interface long module native new ")
	_T("package private protected public requires return short static strictfp ")
	_T("super switch synchronized this throw throws transient try var void ")
	_T("volatile while")
};

const TCHAR* g_jsKeywords
{
	/* https://www.w3schools.com/js/js_reserved.asp */
	_T("abstract arguments await boolean break byte case catch char class const ")
	_T("continue debugger default delete do double else enum eval export extends ")
	_T("false final finally float for function goto if implements import in ")
	_T("instanceof int interface let long native new null package private ")
	_T("protected public return short static super switch synchronized this throw ")
	_T("throws transient true try typeof var void volatile while with yield")
};

const TCHAR* g_matlabKeywords
{
	_T("break case catch classdef continue else elseif end for function global ")
	_T("if otherwise parfor persistent return spmd switch try while")
};

const TCHAR* g_pyKeywords
{
	/* https://www.w3schools.com/python/python_ref_keywords.asp */
	_T("and as assert break class continue def del elif else except False finally ")
	_T("for from global if import in is lambda None nonlocal not or pass raise ")
	_T("return True try while with yield")
};

const TCHAR* g_rKeywords
{
	_T("if else repeat while function for next break TRUE FALSE NULL Inf NaN NA ")
	_T("NA_integer_ NA_real_ NA_complex_ NA_character_")
};

const TCHAR* g_rsKeywords
{
	/* https://doc.rust-lang.org/reference/keywords.html */
	_T("as break const continue crate else enum extern false fn for if impl in ")
	_T("let loop match mod move mut pub ref return self static struct super trait ")
	_T("true type unsafe use where while async await dyn abstract become box do ")
	_T("final macro override priv typeof unsized virtual yield try macro_rules ")
	_T("union dyn")
};

const TCHAR* g_sqlKeywords
{
	/* https://www.w3schools.com/sql/sql_ref_keywords.asp */
	_T("add constraint all alter all and any as asc backup between by case check ")
	_T("column constraint create database default delete desc distinct drop exec ")
	_T("exists foreign from full group having if in into index inner insert is join ")
	_T("left like limit not null or order outer primary key procedure replace right ")
	_T("rownum select set table top truncate union unique update values view where ")
	/* MySQL Data Types */
	_T("char varchar binary varbinary tinyblob tinytext text blob mediumtext ")
	_T("mediumblob longtext longblob enum set bit tinyint bool boolean smallin ")
	_T("mediumint int integer bigint float double precision decimal dec date ")
	_T("datetime timestamp time year references ")
	/* MySQL String Functions */
	_T("ascii char_length character_length concat concat_ws field find_in_set ")
	_T("format instr lcase left length locate lower lpad ltrim mid position ")
	_T("repeat replace reverse right rpad rtrim space strcmp substr substring ")
	_T("substring_index trim ucase upper ")
	/* MySQL Numeric Functions */
	_T("abs acos asin atan atan2 avg ceil ceiling cos cot count degrees div exp ")
	_T("floor greatest least ln log log10 log2 max min mod pi pow power radians ")
	_T("rand round sign sin sqrt sum tan truncate ")
	/* MySQL Date Functions */
	_T("adddate addtime curdate current_date current_time current_timestamp curtime ")
	_T("date datediff date_add date_format date_sub day dayname dayofmonth dayofweek ")
	_T("dayofyear extract from_days hour last_day localtime localtimestamp makedate ")
	_T("maketime microsecond minute month monthname now period_add period_diff quarter ")
	_T("second sec_to_time str_to_date subdate subtime sysdate time time_format ")
	_T("time_to_sec timediff timestamp to_days week weekday weekofyear year yearweek ")
	/* MySQL Advanced Functions */
	_T("bin case cast coalesce connection_id conv convert current_user database ifnull ")
	_T("isnull last_insert_id nullif session_user system_user user version")
};

const TCHAR* g_tclKeywords
{
	/* https://www.tcl-lang.org/man/tcl8.5/UserCmd/contents.htm */
	_T("tclsh wish ")
	/* Tcl commands */
	_T("after append apply array auto_execok auto_import auto_load auto_mkindex ")
	_T("auto_mkindex_old auto_qualify auto_reset bgerror binary break catch cd ")
	_T("chan clock close concat continue dde dict encoding eof error eval exec ")
	_T("exit expr fblocked fconfigure fcopy file fileevent filename flush for ")
	_T("foreach format gets glob global history http if incr info interp join ")
	_T("lappend lassign lindex linsert list llength load lrange lrepeat lreplace ")
	_T("lreverse lsearch lset lsort mathfunc mathop memory msgcat namespace open ")
	_T("package parray pid pkg::create pkg_mkIndex platform platform::shell proc ")
	_T("puts pwd re_syntax read refchan regexp registry regsub rename return ")
	_T("Safe Base scan seek set socket source split string subst switch Tcl ")
	_T("tcl_endOfWord tcl_findLibrary tcl_startOfNextWord tcl_startOfPreviousWord ")
	_T("tcl_wordBreakAfter tcl_wordBreakBefore tcltest tclvars tell time tm trace ")
	_T("unknown unload unset update uplevel upvar variable vwait while ")
	/* Tk commands */
	_T("bell bind bindtags bitmap button canvas checkbutton clipboard colors ")
	_T("console cursors destroy entry event focus font frame grab grid image ")
	_T("keysyms label labelframe listbox loadTk lower menu menubutton message ")
	_T("option options pack panedwindow photo place radiobutton raise scale ")
	_T("scrollbar selection send spinbox text tk tk::mac tk_bisque tk_chooseColor ")
	_T("tk_chooseDirectory tk_dialog tk_focusFollowsMouse tk_focusNext tk_focusPrev ")
	_T("tk_getOpenFile tk_getSaveFile tk_menuSetFocus tk_messageBox tk_optionMenu ")
	_T("tk_popup tk_setPalette tk_textCopy tk_textCut tk_textPaste tkerror tkvars ")
	_T("tkwait toplevel ttk::button ttk::checkbutton ttk::combobox ttk::entry ")
	_T("ttk::frame ttk::intro ttk::label ttk::labelframe ttk::menubutton ")
	_T("ttk::notebook ttk::panedwindow ttk::progressbar ttk::radiobutton ")
	_T("ttk::scale ttk::scrollbar ttk::separator ttk::sizegrip ttk::spinbox ")
	_T("ttk::style ttk::treeview ttk::widget ttk_image ttk_vsapi winfo wm ")
};

CViewTextFileDlg::CViewTextFileDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ViewTextFileDlg, pParent), m_pLexer{ nullptr }
{
	m_nTimerID = 0;
}

CViewTextFileDlg::~CViewTextFileDlg()
{
}

void CViewTextFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT_FILE, m_ctrlTextFile);
}

BEGIN_MESSAGE_MAP(CViewTextFileDlg, CDialogEx)
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CViewTextFileDlg message handlers

std::wstring utf8_to_wstring(const std::string& str)
{
	// convert UTF-8 string to wstring
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.from_bytes(str);
}

std::string wstring_to_utf8(const std::wstring& str)
{
	// convert wstring to UTF-8 string
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.to_bytes(str);
}

void CViewTextFileDlg::SetAStyle(int style, COLORREF fore, COLORREF back, int size, const char* face)
{
	m_ctrlTextFile.StyleSetFore(style, fore);
	m_ctrlTextFile.StyleSetBack(style, back);
	if (size >= 1)
		m_ctrlTextFile.StyleSetSize(style, size);
	if (face)
		m_ctrlTextFile.StyleSetFont(style, face);
}

void CViewTextFileDlg::DefineMarker(int marker, Scintilla::MarkerSymbol markerType, COLORREF fore, COLORREF back)
{
	m_ctrlTextFile.MarkerDefine(marker, markerType);
	m_ctrlTextFile.MarkerSetFore(marker, fore);
	m_ctrlTextFile.MarkerSetBack(marker, back);
}

#define STR_SCINTILLAWND _T("Scintilla")

BOOL CViewTextFileDlg::OnInitDialog()
{
	TCHAR lpszDrive[_MAX_DRIVE] = { 0 };
	TCHAR lpszFolder[_MAX_DIR] = { 0 };
	TCHAR lpszFileName[_MAX_FNAME] = { 0 };
	TCHAR lpszExtension[_MAX_EXT] = { 0 };

	CDialogEx::OnInitDialog();

	SetWindowText(m_strFilePath);

	try
	{
		// try to open the file
		CFile pTextFile(m_strFilePath, CFile::modeRead);
		// query the file's length
		const auto nFileSize = pTextFile.GetLength();
		if (nFileSize > 0)
		{
			// Check if the size of the file to be loaded can be handled via CreateLoader and fail if not
			const auto nFileSizeForLoader{ static_cast<Scintilla::Position>(nFileSize) };
			if (nFileSize != static_cast<ULONGLONG>(nFileSizeForLoader))
			{
				AfxMessageBox(_T("Document is too large to be loaded!"), MB_ICONEXCLAMATION);
				AfxThrowUserException();
			}

			// Create an ILoader instance
			auto pLoader = static_cast<Scintilla::ILoader*>(m_ctrlTextFile.CreateLoader(nFileSizeForLoader, Scintilla::DocumentOption::Default));
			if (pLoader == nullptr)
			{
				AfxMessageBox(_T("Failed to create Loader interface while loading a document!"), MB_ICONEXCLAMATION);
				AfxThrowUserException();
			}

			// Read the data in from the file in blocks
			std::vector<BYTE> byBuffer{ 0x1000, std::allocator<BYTE>{} };
			int nBytesRead{ 0 };
			BOM m_BOM = BOM::Unknown;
			bool bDetectedBOM{ false };
			do
			{
#pragma warning(suppress: 26472)
				nBytesRead = pTextFile.Read(byBuffer.data(), static_cast<UINT>(byBuffer.size()));
				if (nBytesRead)
				{
					int nSkip{ 0 };
					if (!bDetectedBOM)
					{
						bDetectedBOM = true;
						int nUniTest = IS_TEXT_UNICODE_STATISTICS;
						// detect UTF-16BE with BOM
#pragma warning(suppress: 26446)
						if ((nBytesRead > 1) && ((nFileSize % 2) == 0) && ((nBytesRead % 2) == 0) && (byBuffer[0] == 0xFE) && (byBuffer[1] == 0xFF))
						{
							m_BOM = BOM::UTF16BE;
							nSkip = 2;
						}
						// detect UTF-16LE with BOM
#pragma warning(suppress: 26446)
						else if ((nBytesRead > 1) && ((nFileSize % 2) == 0) && ((nBytesRead % 2) == 0) && (byBuffer[0] == 0xFF) && (byBuffer[1] == 0xFE))
						{
							m_BOM = BOM::UTF16LE;
							nSkip = 2;
						}
						// detect UTF-8 with BOM
#pragma warning(suppress: 26446)
						else if ((nBytesRead > 2) && (byBuffer[0] == 0xEF) && (byBuffer[1] == 0xBB) && (byBuffer[2] == 0xBF))
						{
							m_BOM = BOM::UTF8;
							nSkip = 3;
						}
						// detect UTF-16LE without BOM (Note IS_TEXT_UNICODE_STATISTICS implies Little Endian for all versions of supported Windows platforms i.e. x86, x64, ARM & ARM64)
#pragma warning(suppress: 26446)
						else if ((nBytesRead > 1) && ((nFileSize % 2) == 0) && ((nBytesRead % 2) == 0) && (byBuffer[0] != 0) && (byBuffer[1] == 0) && IsTextUnicode(byBuffer.data(), nBytesRead, &nUniTest))
						{
							m_BOM = BOM::UTF16LE_NOBOM;
							nSkip = 0;
						}
					}

					// Work out the data to pass to ILoader->AddData
					const char* pLoadData{ nullptr };
					int nBytesToLoad{ 0 };
					CStringA sUTF8Data;
					if ((m_BOM == BOM::UTF16LE_NOBOM) || (m_BOM == BOM::UTF16LE))
					{
						// Handle conversion from UTF16LE to UTF8
#pragma warning(suppress: 26481 26490)
						sUTF8Data = Scintilla::CScintillaCtrl::W2UTF8(reinterpret_cast<const wchar_t*>(byBuffer.data() + nSkip), (nBytesRead - nSkip) / 2);
						pLoadData = sUTF8Data;
						nBytesToLoad = sUTF8Data.GetLength();
					}
					else if (m_BOM == BOM::UTF16BE)
					{
						// Handle conversion from UTF16BE to UTF8
#pragma warning(suppress: 26429 26481)
						BYTE* p = byBuffer.data() + nSkip;
						const int nUTF16CharsRead = (nBytesRead - nSkip) / 2;
						for (int i = 0; i < nUTF16CharsRead; i++)
						{
							const BYTE t{ *p };
#pragma warning(suppress: 26481)
							* p = p[1];
#pragma warning(suppress: 26481)
							p[1] = t;
#pragma warning(suppress: 26481)
							p += 2;
						}
#pragma warning(suppress: 26481 26490)
						sUTF8Data = Scintilla::CScintillaCtrl::W2UTF8(reinterpret_cast<const wchar_t*>(byBuffer.data() + nSkip), (nBytesRead - nSkip) / 2);
						pLoadData = sUTF8Data;
						nBytesToLoad = sUTF8Data.GetLength();
					}
					else
					{
#pragma warning(suppress: 26481 26490)
						pLoadData = reinterpret_cast<const char*>(byBuffer.data()) + nSkip;
						nBytesToLoad = nBytesRead - nSkip;
					}
					ASSERT(pLoadData != nullptr);
					const auto nAddDataError{ pLoader->AddData(pLoadData, nBytesToLoad) };
					if (nAddDataError != SC_STATUS_OK)
					{
						pLoader->Release();
						CString sError;
						sError.Format(_T("%d"), nAddDataError);
						AfxMessageBox(_T("Failed to load document!"), MB_ICONEXCLAMATION);
						AfxThrowUserException();
					}
				}
			} while (nBytesRead);

			// Set the document pointer to the loaded content
			m_ctrlTextFile.SetDocPointer(static_cast<Scintilla::IDocumentEditable*>(pLoader->ConvertToDocument())); //NOLINT(clang-analyzer-core.CallAndMessage)

			// If we detected UTF data, then use the UTF8 codepage else disable multi-byte support
			if (m_BOM == BOM::Unknown)
				m_ctrlTextFile.SetCodePage(0);
			else
				m_ctrlTextFile.SetCodePage(Scintilla::CpUtf8);

			// Reinitialize the control settings
			m_ctrlTextFile.SetUndoCollection(TRUE);
			m_ctrlTextFile.EmptyUndoBuffer();
			m_ctrlTextFile.SetSavePoint();
			m_ctrlTextFile.GotoPos(0);
		}
		// close the file handle
		pTextFile.Close();
	}
	catch (CFileException* pEx)
	{
		// if an error occurs, just make a message box
		pEx->ReportError();
		pEx->Delete();
		CDialogEx::EndDialog(IDCANCEL);
	}

	CString strTempPath = m_strFilePath;
	strTempPath.MakeLower();
	_tsplitpath_s(strTempPath,
		lpszDrive, _MAX_DRIVE,
		lpszFolder, _MAX_DIR,
		lpszFileName, _MAX_FNAME,
		lpszExtension, _MAX_EXT);

	if (_tcsicmp(lpszExtension, _T(".bat")) == 0)
	{
		// Create the Batch Lexer
#pragma warning(suppress: 26429)
		m_pLexer = theApp.m_pCreateLexer("batch");
		if (m_pLexer == nullptr)
			return FALSE;

		// Setup the Batch Lexer
		m_ctrlTextFile.SetILexer(m_pLexer);
	}
	else
	{
		if ((_tcsicmp(lpszExtension, _T(".cmake")) == 0) || 
			((_tcsicmp(lpszFileName, _T("cmakelists")) == 0) && (_tcsicmp(lpszExtension, _T(".txt")) == 0)))
		{
			// Create the CMake Lexer
#pragma warning(suppress: 26429)
			m_pLexer = theApp.m_pCreateLexer("cmake");
			if (m_pLexer == nullptr)
				return FALSE;

			// Setup the CMake Lexer
			m_ctrlTextFile.SetILexer(m_pLexer);
			m_ctrlTextFile.SetKeyWords(0, g_cmakeKeywords);
		}
		else
		{
			if ((_tcsicmp(lpszExtension, _T(".c")) == 0) ||
				(_tcsicmp(lpszExtension, _T(".cpp")) == 0) ||
				(_tcsicmp(lpszExtension, _T(".cxx")) == 0) ||
				(_tcsicmp(lpszExtension, _T(".h")) == 0) ||
				(_tcsicmp(lpszExtension, _T(".hpp")) == 0))
			{
				// Create the C++ Lexer
#pragma warning(suppress: 26429)
				m_pLexer = theApp.m_pCreateLexer("cpp");
				if (m_pLexer == nullptr)
					return FALSE;

				// Setup the C++ Lexer
				m_ctrlTextFile.SetILexer(m_pLexer);
				m_ctrlTextFile.SetKeyWords(0, g_cppKeywords);
			}
			else
			{
				if (_tcsicmp(lpszExtension, _T(".cs")) == 0)
				{
					// Create the C++ Lexer
#pragma warning(suppress: 26429)
					m_pLexer = theApp.m_pCreateLexer("cpp");
					if (m_pLexer == nullptr)
						return FALSE;

					// Setup the C++ Lexer
					m_ctrlTextFile.SetILexer(m_pLexer);
					m_ctrlTextFile.SetKeyWords(0, g_csKeywords);
				}
				else
				{
					if (_tcsicmp(lpszExtension, _T(".css")) == 0)
					{
						// Create the CSS Lexer
#pragma warning(suppress: 26429)
						m_pLexer = theApp.m_pCreateLexer("css");
						if (m_pLexer == nullptr)
							return FALSE;

						// Setup the CSS Lexer
						m_ctrlTextFile.SetILexer(m_pLexer);
					}
					else
					{
						if (_tcsicmp(lpszExtension, _T(".groovy")) == 0)
						{
							// Create the C++ Lexer
#pragma warning(suppress: 26429)
							m_pLexer = theApp.m_pCreateLexer("cpp");
							if (m_pLexer == nullptr)
								return FALSE;

							// Setup the C++ Lexer
							m_ctrlTextFile.SetILexer(m_pLexer);
							m_ctrlTextFile.SetKeyWords(0, g_groovyKeywords);
						}
						else
						{
							if (_tcsicmp(lpszExtension, _T(".java")) == 0)
							{
								// Create the C++ Lexer
#pragma warning(suppress: 26429)
								m_pLexer = theApp.m_pCreateLexer("cpp");
								if (m_pLexer == nullptr)
									return FALSE;

								// Setup the C++ Lexer
								m_ctrlTextFile.SetILexer(m_pLexer);
								m_ctrlTextFile.SetKeyWords(0, g_javaKeywords);
							}
							else
							{
								if (_tcsicmp(lpszExtension, _T(".js")) == 0)
								{
									// Create the C++ Lexer
#pragma warning(suppress: 26429)
									m_pLexer = theApp.m_pCreateLexer("cpp");
									if (m_pLexer == nullptr)
										return FALSE;

									// Setup the C++ Lexer
									m_ctrlTextFile.SetILexer(m_pLexer);
									m_ctrlTextFile.SetKeyWords(0, g_jsKeywords);
								}
								else
								{
									if ((_tcsicmp(lpszExtension, _T(".htm")) == 0) ||
										(_tcsicmp(lpszExtension, _T(".html")) == 0) ||
										(_tcsicmp(lpszExtension, _T(".asp")) == 0) ||
										(_tcsicmp(lpszExtension, _T(".aspx")) == 0) ||
										(_tcsicmp(lpszExtension, _T(".php")) == 0))
									{
										// Create the HTML Lexer
#pragma warning(suppress: 26429)
										m_pLexer = theApp.m_pCreateLexer("hypertext");
										if (m_pLexer == nullptr)
											return FALSE;

										// Setup the HTML Lexer
										m_ctrlTextFile.SetILexer(m_pLexer);
									}
									else
									{
										if (_tcsicmp(lpszExtension, _T(".json")) == 0)
										{
											// Create the JSON Lexer
#pragma warning(suppress: 26429)
											m_pLexer = theApp.m_pCreateLexer("json");
											if (m_pLexer == nullptr)
												return FALSE;

											// Setup the JSON Lexer
											m_ctrlTextFile.SetILexer(m_pLexer);
										}
										else
										{
											if (_tcsicmp(lpszExtension, _T(".m")) == 0)
											{
												// Create the Matlab Lexer
#pragma warning(suppress: 26429)
												m_pLexer = theApp.m_pCreateLexer("matlab");
												if (m_pLexer == nullptr)
													return FALSE;

												// Setup the Matlab Lexer
												m_ctrlTextFile.SetILexer(m_pLexer);
												m_ctrlTextFile.SetKeyWords(0, g_matlabKeywords);
											}
											else
											{
												if ((_tcsicmp(lpszExtension, _T(".mak")) == 0) ||
													(_tcsicmp(lpszFileName, _T("makefile")) == 0))
												{
													// Create the Makefile Lexer
#pragma warning(suppress: 26429)
													m_pLexer = theApp.m_pCreateLexer("makefile");
													if (m_pLexer == nullptr)
														return FALSE;

													// Setup the Makefile Lexer
													m_ctrlTextFile.SetILexer(m_pLexer);
												}
												else
												{
													if (_tcsicmp(lpszExtension, _T(".md")) == 0)
													{
														// Create the MD Lexer
#pragma warning(suppress: 26429)
														m_pLexer = theApp.m_pCreateLexer("markdown");
														if (m_pLexer == nullptr)
															return FALSE;

														// Setup the MD Lexer
														m_ctrlTextFile.SetILexer(m_pLexer);
													}
													else
													{
														if (_tcsicmp(lpszExtension, _T(".py")) == 0)
														{
															// Create the Python Lexer
#pragma warning(suppress: 26429)
															m_pLexer = theApp.m_pCreateLexer("python");
															if (m_pLexer == nullptr)
																return FALSE;

															// Setup the Python Lexer
															m_ctrlTextFile.SetILexer(m_pLexer);
															m_ctrlTextFile.SetKeyWords(0, g_pyKeywords);
														}
														else
														{
															if (_tcsicmp(lpszExtension, _T(".r")) == 0)
															{
																// Create the R Lexer
#pragma warning(suppress: 26429)
																m_pLexer = theApp.m_pCreateLexer("r");
																if (m_pLexer == nullptr)
																	return FALSE;

																// Setup the R Lexer
																m_ctrlTextFile.SetILexer(m_pLexer);
																m_ctrlTextFile.SetKeyWords(0, g_rKeywords);
															}
															else
															{
																if (_tcsicmp(lpszExtension, _T(".rs")) == 0)
																{
																	// Create the Rust Lexer
#pragma warning(suppress: 26429)
																	m_pLexer = theApp.m_pCreateLexer("rust");
																	if (m_pLexer == nullptr)
																		return FALSE;

																	// Setup the Rust Lexer
																	m_ctrlTextFile.SetILexer(m_pLexer);
																	m_ctrlTextFile.SetKeyWords(0, g_rsKeywords);
																}
																else
																{
																	if (_tcsicmp(lpszExtension, _T(".sh")) == 0)
																	{
																		// Create the Shell Lexer
#pragma warning(suppress: 26429)
																		m_pLexer = theApp.m_pCreateLexer("bash");
																		if (m_pLexer == nullptr)
																			return FALSE;

																		// Setup the Shell Lexer
																		m_ctrlTextFile.SetILexer(m_pLexer);
																	}
																	else
																	{
																		if (_tcsicmp(lpszExtension, _T(".sql")) == 0)
																		{
																			// Create the SQL Lexer
#pragma warning(suppress: 26429)
																			m_pLexer = theApp.m_pCreateLexer("sql");
																			if (m_pLexer == nullptr)
																				return FALSE;

																			// Setup the SQL Lexer
																			m_ctrlTextFile.SetILexer(m_pLexer);
																			m_ctrlTextFile.SetKeyWords(0, g_sqlKeywords);
																		}
																		else
																		{
																			if (_tcsicmp(lpszExtension, _T(".tcl")) == 0)
																			{
																				// Create the TCL Lexer
#pragma warning(suppress: 26429)
																				m_pLexer = theApp.m_pCreateLexer("tcl");
																				if (m_pLexer == nullptr)
																					return FALSE;

																				// Setup the TCL Lexer
																				m_ctrlTextFile.SetILexer(m_pLexer);
																				m_ctrlTextFile.SetKeyWords(0, g_tclKeywords);
																			}
																			else
																			{
																				if (_tcsicmp(lpszExtension, _T(".xml")) == 0)
																				{
																					// Create the XML Lexer
#pragma warning(suppress: 26429)
																					m_pLexer = theApp.m_pCreateLexer("xml");
																					if (m_pLexer == nullptr)
																						return FALSE;

																					// Setup the XML Lexer
																					m_ctrlTextFile.SetILexer(m_pLexer);
																				}
																				else
																				{
																					m_ctrlTextFile.SetupDirectAccess();
																					m_ctrlTextFile.SetILexer(nullptr);
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	SetAStyle(static_cast<int>(Scintilla::StylesCommon::Default), RGB(0, 0, 0), RGB(0xff, 0xff, 0xff), 10, "Consolas");
	// Setup styles
	m_ctrlTextFile.StyleClearAll();
	SetAStyle(SCE_C_DEFAULT, RGB(0, 0, 0));
	SetAStyle(SCE_C_COMMENT, RGB(0, 0x80, 0));
	SetAStyle(SCE_C_COMMENTLINE, RGB(0, 0x80, 0));
	SetAStyle(SCE_C_COMMENTDOC, RGB(0, 0x80, 0));
	SetAStyle(SCE_C_COMMENTLINEDOC, RGB(0, 0x80, 0));
	SetAStyle(SCE_C_COMMENTDOCKEYWORD, RGB(0, 0x80, 0));
	SetAStyle(SCE_C_COMMENTDOCKEYWORDERROR, RGB(0, 0x80, 0));
	SetAStyle(SCE_C_NUMBER, RGB(0, 0x80, 0x80));
	SetAStyle(SCE_C_WORD, RGB(0, 0, 0x80));
	m_ctrlTextFile.StyleSetBold(SCE_C_WORD, 1);
	SetAStyle(SCE_C_STRING, RGB(0x80, 0, 0x80));
	SetAStyle(SCE_C_IDENTIFIER, RGB(0, 0, 0));
	SetAStyle(SCE_C_PREPROCESSOR, RGB(0x80, 0, 0));
	SetAStyle(SCE_C_OPERATOR, RGB(0x80, 0x80, 0));
	/* TCL/TK */
	SetAStyle(SCE_TCL_DEFAULT, RGB(0, 0, 0));
	SetAStyle(SCE_TCL_COMMENT, RGB(0, 0x80, 0));
	SetAStyle(SCE_TCL_COMMENTLINE, RGB(0, 0x80, 0));
	SetAStyle(SCE_TCL_COMMENT_BOX, RGB(0, 0x80, 0));
	SetAStyle(SCE_TCL_BLOCK_COMMENT, RGB(0, 0x80, 0));
	SetAStyle(SCE_TCL_NUMBER, RGB(0, 0x80, 0x80));
	SetAStyle(SCE_TCL_WORD, RGB(0, 0, 0x80));
	m_ctrlTextFile.StyleSetBold(SCE_TCL_WORD, 1);
	SetAStyle(SCE_TCL_WORD2, RGB(0, 0, 0x80));
	m_ctrlTextFile.StyleSetBold(SCE_TCL_WORD2, 1);
	SetAStyle(SCE_TCL_WORD3, RGB(0, 0, 0x80));
	m_ctrlTextFile.StyleSetBold(SCE_TCL_WORD3, 1);
	SetAStyle(SCE_TCL_WORD4, RGB(0, 0, 0x80));
	m_ctrlTextFile.StyleSetBold(SCE_TCL_WORD4, 1);
	SetAStyle(SCE_TCL_WORD5, RGB(0, 0, 0x80));
	m_ctrlTextFile.StyleSetBold(SCE_TCL_WORD5, 1);
	SetAStyle(SCE_TCL_WORD6, RGB(0, 0, 0x80));
	m_ctrlTextFile.StyleSetBold(SCE_TCL_WORD6, 1);
	SetAStyle(SCE_TCL_WORD7, RGB(0, 0, 0x80));
	m_ctrlTextFile.StyleSetBold(SCE_TCL_WORD7, 1);
	SetAStyle(SCE_TCL_WORD8, RGB(0, 0, 0x80));
	m_ctrlTextFile.StyleSetBold(SCE_TCL_WORD8, 1);
	SetAStyle(SCE_TCL_IN_QUOTE, RGB(0x80, 0, 0x80));
	SetAStyle(SCE_TCL_IDENTIFIER, RGB(0, 0, 0));
	SetAStyle(SCE_TCL_OPERATOR, RGB(0x80, 0x80, 0));

	// Setup folding
	m_ctrlTextFile.SetMarginWidthN(2, 16);
	m_ctrlTextFile.SetMarginSensitiveN(2, TRUE);
	m_ctrlTextFile.SetMarginTypeN(2, Scintilla::MarginType::Symbol);
	m_ctrlTextFile.SetMarginMaskN(2, Scintilla::MaskFolders);
	m_ctrlTextFile.SetSCIProperty(_T("fold"), _T("1"));

	// Setup markers
	DefineMarker(static_cast<int>(Scintilla::MarkerOutline::FolderOpen), Scintilla::MarkerSymbol::Minus, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0xFF));
	DefineMarker(static_cast<int>(Scintilla::MarkerOutline::Folder), Scintilla::MarkerSymbol::Plus, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));
	DefineMarker(static_cast<int>(Scintilla::MarkerOutline::FolderSub), Scintilla::MarkerSymbol::Empty, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));
	DefineMarker(static_cast<int>(Scintilla::MarkerOutline::FolderTail), Scintilla::MarkerSymbol::Empty, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));
	DefineMarker(static_cast<int>(Scintilla::MarkerOutline::FolderEnd), Scintilla::MarkerSymbol::Empty, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));
	DefineMarker(static_cast<int>(Scintilla::MarkerOutline::FolderOpenMid), Scintilla::MarkerSymbol::Empty, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));
	DefineMarker(static_cast<int>(Scintilla::MarkerOutline::FolderMidTail), Scintilla::MarkerSymbol::Empty, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));

	// Setup auto completion
	m_ctrlTextFile.AutoCSetSeparator(10); // Use a separator of line feed

	// Setup call tips
	m_ctrlTextFile.SetMouseDwellTime(1000);

	// Enable Multiple selection
	// m_ctrlTextFile.SetMultipleSelection(TRUE);

	VERIFY(m_pWindowResizer.Hook(this));
	VERIFY(m_pWindowResizer.SetAnchor(IDC_TEXT_FILE, ANCHOR_LEFT | ANCHOR_RIGHT | ANCHOR_TOP | ANCHOR_BOTTOM));

	const int nWidth = theApp.GetInt(_T("Width"), -1);
	const int nHeight = theApp.GetInt(_T("Height"), -1);
	if ((-1 != nWidth) && (-1 != nHeight))
	{
		CRect pWndRect(0, 0, nWidth, nHeight);
		MoveWindow(pWndRect, FALSE);
		CenterWindow();
		UpdateWindow();
	}

	m_nTimerID = SetTimer(0x1234, 100, nullptr);
	// const int nMarginWidth{ m_ctrlTextFile.GetMarginWidthN(0) };
	m_ctrlTextFile.SetMarginWidthN(0, 32);
	m_ctrlTextFile.SetWrapMode(Scintilla::Wrap::Word);

	m_ctrlTextFile.SetReadOnly(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CViewTextFileDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	RECT pWndRect;
	GetWindowRect(&pWndRect);
	const int nWidth = pWndRect.right - pWndRect.left;
	const int nHeight = pWndRect.bottom - pWndRect.top;
	theApp.WriteInt(_T("Width"), nWidth);
	theApp.WriteInt(_T("Height"), nHeight);
}

void CViewTextFileDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (m_nTimerID == nIDEvent)
	{
		KillTimer(m_nTimerID);
		m_ctrlTextFile.SetSel(0, 0);
	}

	CDialogEx::OnTimer(nIDEvent);
}
