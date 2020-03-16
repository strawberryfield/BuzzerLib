/// @file
/// RTTTL manager class implementation.
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

#include "RTTTL.h"

RTTTLClass::RTTTLClass(char songString[])
{
    init(songString);
}

void RTTTLClass::init(char songString[])
{
    cursor = 0;
    song = songString;
    //   Serial.println(song);

    // skip song title
    for (; song[cursor] != ':'; ++cursor)
    {
    }
    ++cursor;

    // parse header
    for (; song[cursor] != ':'; ++cursor)
    {
        switch (song[cursor])
        {
        case 'd':
            defaultDurate = getValue();
            break;
        case 'o':
            defaultOctave = getValue();
            break;
        case 'b':
            bpm = getValue();
            beatms = 240000 / bpm;
            break;

        default:
            break;
        }
    }

    streamStart = ++cursor;
}

void RTTTLClass::restart()
{
    cursor = streamStart;
}

///@brief
/// Test function for header values
bool headerTest(char c)
{
    return c != ',' && c != ':';
}

///@brief
/// Test function for duration value
bool durationTest(char c)
{
    return !isAlpha(c);
}

uint8_t RTTTLClass::getValue(bool (*testFunction)(char))
{
    char str[] = "0  ";
    uint8_t j = 0;
    for (; testFunction(song[cursor]); ++cursor)
    {
        if (isDigit(song[cursor]))
        {
            str[j] = song[cursor];
            ++j;
        }
    }
    if (song[cursor] == ':')
        --cursor;
    int ret;
    sscanf(str, "%d", &ret);
    return ret;
}

uint8_t RTTTLClass::getValue()
{
    return getValue(&headerTest);
}

NoteClass RTTTLClass::next()
{
    // No more notes
    if (song[cursor] == 0)
        return NoteClass(0, 0);

    uint8_t durate = defaultDurate;
    uint8_t octave = defaultOctave;
    char note = ' ';
    char diesis = ' ';

    // durate
    if (isDigit(song[cursor]))
    {
        durate = getValue(&durationTest);
    }

    // note
    note = song[cursor];
    ++cursor;

    // diesis
    if (song[cursor] == '#')
    {
        diesis = '#';
        ++cursor;
    }

    // dot
    if (song[cursor] == '.')
    {
        durate += durate >> 1;
        ++cursor;
    }

    // octave
    if (isDigit(song[cursor]))
    {
        octave = song[cursor] - '0';
        ++cursor;
    }

    // skip comma
    if (song[cursor] == ',')
        ++cursor;

    if (toUpperCase(note) == 'P')
    {
        return NoteClass(0, (uint16_t)(beatms / durate));
    }
    else
    {
        return NoteClass(note, diesis, octave, (uint16_t)(beatms / durate));
    }
}