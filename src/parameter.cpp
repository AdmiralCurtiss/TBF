/**
 * This file is part of Tales of Berseria "Fix".
 *
 * Tales of Berseria "Fix" is free software : you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by The Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * Tales of Berseria "Fix" is distributed in the hope that it will be
 * useful,
 *
 * But WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Tales of Berseria "Fix".
 *
 *   If not, see <http://www.gnu.org/licenses/>.
 *
**/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS

#include "parameter.h"

std::wstring
tbf::ParameterInt::get_value_str (void)
{
  wchar_t str [32];
  _itow (value, str, 10);

  return std::wstring (str);
}

int
tbf::ParameterInt::get_value (void)
{
  return value;
}

void
tbf::ParameterInt::set_value (int val)
{
  value = val;
}


void
tbf::ParameterInt::set_value_str (std::wstring str)
{
  value = _wtoi (str.c_str ());
}


void
tbf::ParameterInt::store_str (std::wstring str)
{
  set_value_str  (str);
  iParameter::store ();
}

void
tbf::ParameterInt::store (int val)
{
  set_value      (val);
  iParameter::store ();
}

bool
tbf::ParameterInt::load (int& ref)
{
  bool bRet = 
    iParameter::load ();

  if (bRet)
    ref = get_value ();

  return bRet;
}



std::wstring
tbf::ParameterInt64::get_value_str (void)
{
  wchar_t str [32];
  _i64tow (value, str, 10);

  return std::wstring (str);
}

int64_t
tbf::ParameterInt64::get_value (void)
{
  return value;
}

void
tbf::ParameterInt64::set_value (int64_t val)
{
  value = val;
}


void
tbf::ParameterInt64::set_value_str (std::wstring str)
{
  value = _wtoll (str.c_str ());
}


void
tbf::ParameterInt64::store_str (std::wstring str)
{
  set_value_str  (str);
  iParameter::store ();
}

void
tbf::ParameterInt64::store (int64_t val)
{
  set_value      (val);
  iParameter::store ();
}

bool
tbf::ParameterInt64::load (int64_t& ref)
{
  bool bRet = 
    iParameter::load ();

  if (bRet)
    ref = get_value ();

  return bRet;
}



std::wstring
tbf::ParameterBool::get_value_str (void)
{
  switch (type) {
    case ZeroNonZero:
      return value  ?  L"1"    : L"0";
    case YesNo:
      return value  ?  L"Yes"  : L"No";
    case OnOff:
      return value  ?  L"On"   : L"Off";
    case TrueFalse:
    default:
      return value  ?  L"True" : L"False";
  }
}

bool
tbf::ParameterBool::get_value (void)
{
  return value;
}

void
tbf::ParameterBool::set_value (bool val)
{
  value = val;
}


void
tbf::ParameterBool::set_value_str (std::wstring str)
{
  size_t len = str.length ();

  type = TrueFalse;

  switch (len)
  {
    case 1:
      type = ZeroNonZero;

      if (str [0] == L'1')
        value = true;
      break;

    case 2:
      if ( towlower (str [0]) == L'o' &&
           towlower (str [1]) == L'n' ) {
        type  = OnOff;
        value = true;
      } else if ( towlower (str [0]) == L'n' &&
                  towlower (str [1]) == L'o' ) {
        type  = YesNo;
        value = false;
      }
      break;

    case 3:
      if ( towlower (str [0]) == L'y' &&
           towlower (str [1]) == L'e' &&
           towlower (str [2]) == L's' ) {
        type  = YesNo;
        value = true;
      } else if ( towlower (str [0]) == L'o' &&
                  towlower (str [1]) == L'f' &&
                  towlower (str [2]) == L'f' ) {
        type  = OnOff;
        value = false;
      }
      break;

    case 4:
      if ( towlower (str [0]) == L't' &&
           towlower (str [1]) == L'r' &&
           towlower (str [2]) == L'u' &&
           towlower (str [3]) == L'e' )
        value = true;
      break;

    default:
      value = false;
      break;
  }
}


void
tbf::ParameterBool::store_str (std::wstring str)
{
  set_value_str  (str);
  iParameter::store ();
}

void
tbf::ParameterBool::store (bool val)
{
  set_value      (val);
  iParameter::store ();
}

bool
tbf::ParameterBool::load (bool& ref)
{
  bool bRet = 
    iParameter::load ();

  if (bRet)
    ref = get_value ();

  return bRet;
}



std::wstring
tbf::ParameterFloat::get_value_str (void)
{
  wchar_t val_str [16];
  swprintf (val_str, L"%f", value);

  // Remove trailing 0's after the .
  size_t len = wcslen (val_str);
  for (size_t i = (len - 1); i > 1; i--) {
    if (val_str [i] == L'0' && val_str [i - 1] != L'.')
      len--;
    if (val_str [i] != L'0' && val_str [i] != L'\0')
      break;
  }

  val_str [len] = L'\0';

  return std::wstring (val_str);
}

float
tbf::ParameterFloat::get_value (void)
{
  return value;
}

void
tbf::ParameterFloat::set_value (float val)
{
  value = val;
}


void
tbf::ParameterFloat::set_value_str (std::wstring str)
{
  value = (float)wcstod (str.c_str (), NULL);
}


void
tbf::ParameterFloat::store_str (std::wstring str)
{
  set_value_str  (str);
  iParameter::store ();
}

void
tbf::ParameterFloat::store (float val)
{
  set_value      (val);
  iParameter::store ();
}

bool
tbf::ParameterFloat::load (float& ref)
{
  bool bRet = 
    iParameter::load ();

  if (bRet)
    ref = get_value ();

  return bRet;
}



std::wstring
tbf::ParameterStringW::get_value_str (void)
{
  return value;
}

std::wstring
tbf::ParameterStringW::get_value (void)
{
  return value;
}

void
tbf::ParameterStringW::set_value (std::wstring val)
{
  value = val;
}


void
tbf::ParameterStringW::set_value_str (std::wstring str)
{
  value = str;
}


void
tbf::ParameterStringW::store_str (std::wstring str)
{
  set_value_str  (str);
  iParameter::store ();
}

void
tbf::ParameterStringW::store (std::wstring val)
{
  set_value      (val);
  iParameter::store ();
}

bool
tbf::ParameterStringW::load (std::wstring& ref)
{
  bool bRet = 
    iParameter::load ();

  if (bRet)
    ref = get_value ();

  return bRet;
}


template <>
tbf::iParameter*
tbf::ParameterFactory::create_parameter <int> (const wchar_t* name)
{
  iParameter* param = new ParameterInt ();
  params.push_back (param);

  return param;
}

template <>
tbf::iParameter*
tbf::ParameterFactory::create_parameter <int64_t> (const wchar_t* name)
{
  iParameter* param = new ParameterInt64 ();
  params.push_back (param);

  return param;
}

template <>
tbf::iParameter*
tbf::ParameterFactory::create_parameter <bool> (const wchar_t* name)
{
  iParameter* param = new ParameterBool ();
  params.push_back (param);

  return param;
}

template <>
tbf::iParameter*
tbf::ParameterFactory::create_parameter <float> (const wchar_t* name)
{
  iParameter* param = new ParameterFloat ();
  params.push_back (param);

  return param;
}

template <>
tbf::iParameter*
tbf::ParameterFactory::create_parameter <std::wstring> (const wchar_t* name)
{
  iParameter* param = new ParameterStringW ();
  params.push_back (param);

  return param;
}