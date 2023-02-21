// This file is part of Notepad++ project
// Copyright (C)2021 Don HO <don.h@free.fr>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
#pragma once
#include "Notepad_plus.h"

const int splitterSize = 8;


class Notepad_plus_Window : public Window
{
public:
	void init(HINSTANCE, HWND, const TCHAR *cmdLine, CmdLineParams *cmdLineParams);

	bool isDlgsMsg(MSG *msg) const;

	HACCEL getAccTable() const {
		return _notepad_plus_plus_core.getAccTable();
	};

	bool emergency(const generic_string& emergencySavedDir) {
		return _notepad_plus_plus_core.emergency(emergencySavedDir);
	};

	bool isPrelaunch() const {
		return _isPrelaunch;
	};

	void setIsPrelaunch(bool val) {
		_isPrelaunch = val;
	};

	generic_string getPluginListVerStr() const {
		return _notepad_plus_plus_core.getPluginListVerStr();
	};

	virtual void destroy() {
		if (_hIconAbsent)
			::DestroyIcon(_hIconAbsent);
		::DestroyWindow(_hSelf);
	};

	static const TCHAR * getClassName() {
		return _className;
	};

	HICON getAbsentIcoHandle() {
		return _hIconAbsent;
	};

	static HWND gNppHWND;	//static handle to Notepad++ window, NULL if non-existant

	void setStartupBgColor(COLORREF BgColor);

private:
	Notepad_plus _notepad_plus_plus_core;
	static LRESULT CALLBACK Notepad_plus_Proc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);
	LRESULT runProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam);

	static const TCHAR _className[32];
	bool _isPrelaunch = false;
	bool _disablePluginsManager = false;

	QuoteParams _quoteParams; // keep the availability of quote parameters for thread using
	std::wstring _userQuote; // keep the availability of this string for thread using

	HICON _hIconAbsent = nullptr;
};
