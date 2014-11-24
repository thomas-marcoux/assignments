{
   3.pas
   
   Copyright 2014 sorel <sorel@ubuntu>
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.
   
   
}


program untitled;

uses crt;

var j, k: integer;
c: array[1..4] of integer;

procedure mix(w, x, y, z: integer);
	var k : integer;
	BEGIN
		k := 3;
		c[j] := w + 3;
		j := y + 2;
		x := x + 6;
		c[k] := z + 7;
	END;
	
BEGIN
	c[1] := 1;
	c[2] := 3;
	c[3] := 5;
	c[4] := 7;
	j := 1;
	k := 2;
	mix(j, c[j], k, c[k]);
	writeln(c[1], ' ', c[2], ' ', c[3], ' ', c[4]);
END.


