/// @file
/// RTTTL manager class definition.
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

#ifndef _RTTTL_h
#define _RTTTL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Note.h"

class RTTTLClass
{
protected:
    char *song;
    uint16_t cursor;
    uint16_t streamStart;

    uint8_t defaultOctave;
    uint8_t defaultDurate;
    uint8_t bpm;
    uint16_t beatms;

    uint8_t getValue();                           //!< Header values parser
    uint8_t getValue(bool (*testFunction)(char)); //!< Generic number parser
public:
    RTTTLClass(){};                //!< Empty constructor
    RTTTLClass(char songString[]); //!< Cnstructor
    void init(char songString[]);  //!< Inits from string

    void restart();   //!< Restart play
    NoteClass next(); //!< Gets next note
};

#endif
