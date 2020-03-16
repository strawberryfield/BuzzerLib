/// @file
/// Note class implementation.
///
/// @author
/// copyright (c) 2020 Roberto Ceccarelli - Casasoft
/// http://strawberryfield.altervista.org
///
/// @copyright
/// This is free software:
/// you can redistribute it and/or modify it
/// under the terms of the GNU General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
///
/// You should have received a copy of the GNU General Public License
/// along with these files.
/// If not, see <http://www.gnu.org/licenses/>.
///
/// @remark
/// This software is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
/// See the GNU General Public License for more details.
///

#include "Note.h"

NoteClass::NoteClass(char note, char diesis, uint8_t octave, uint16_t Duration)
{
    switch (toUpperCase(note))
    {
    case 'A':
        frequency = (diesis == '#' ? NOTE_AS7 : NOTE_A7);
        break;
    case 'B':
        frequency = NOTE_B7;
        break;
    case 'C':
        frequency = (diesis == '#' ? NOTE_CS8 : NOTE_C8);
        break;
    case 'D':
        frequency = (diesis == '#' ? NOTE_DS8 : NOTE_D8);
        break;
    case 'E':
        frequency = NOTE_E8;
        break;
    case 'F':
        frequency = (diesis == '#' ? NOTE_FS8 : NOTE_F8);
        break;
    case 'G':
        frequency = (diesis == '#' ? NOTE_GS8 : NOTE_G8);
        break;

    default:
        break;
    }

    int shift = 8 - octave;
    if (shift > 0)
        frequency = frequency >> shift;
    if (shift < 0)
        frequency = frequency << -shift;
    duration = Duration;
}
