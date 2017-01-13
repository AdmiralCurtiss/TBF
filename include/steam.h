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
#ifndef __TBF__STEAM_H__
#define __TBF__STEAM_H__

#include "command.h"

namespace tbf
{
  namespace SteamFix
  {
    void Init     (void);
    void Shutdown (void);

    void SetOverlayState (bool active);

    class CommandProcessor : public SK_IVariableListener {
    public:
      CommandProcessor (void);

      virtual bool OnVarChange (SK_IVariable* var, void* val = NULL);

      static CommandProcessor* getInstance (void)
      {
        if (pCommProc == NULL)
          pCommProc = new CommandProcessor ();

        return pCommProc;
      }

    protected:
      SK_IVariable* allow_broadcasts_;

    private:
      static CommandProcessor* pCommProc;
    };

    // Hold a reference to the Steam DLL
    extern HMODULE steam_dll;
  }
}


#endif /* __TBF__STEAM_H__ */