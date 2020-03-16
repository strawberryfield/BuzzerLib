/// @file 
/// Song player example.
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
/// @name Wiring diagram
/// @image html BaseDisplay_bb.jpg
///

#include "Buzzer.h"
#include "RTTTL.h"

RTTTLClass song;

/** the setup function runs once when you press reset or power the board */
void setup() {
	Buzzer.init(2);
	song.init("MammaMia:d=16,o=5,b=40:f6,d#6,f6,4d#6,d#6,d#6,f6,g6,f6,8d#.6,p,8f6,4d#6,8g#6,g#6,g#6,g#6,8g6,8d#.6,p,4a#6,a#6,a#6,8a#6,8f6,8g6,4g#6,8g6,8g6,g6,8g6,8d6,8d#6,4f6,8f6,4d#6,8g#6,g#6,g#6,g#6,g6,d#6,f6,8d#6");
	Buzzer.playSong(song);
}

/** the loop function runs over and over again until power down or reset */
void loop() {
	Buzzer.loop();
}
