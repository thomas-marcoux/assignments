{
   2.pas
   
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

var i, j, k: integer;
a: array[1..4] of integer;

procedure foo(x, y, z, w: integer);
	var j : integer;
	BEGIN
		j := 3;
		a[i] := x + 2;
		i := z + 2;
		y := y + 7;
		a[j] := w + 4;
	END;
	
BEGIN
	a[1] := 1;
	a[2] := 2;
	a[3] := 3;
	a[4] := 4;
	i := 1;
	j := 2;
	k := 3;
	foo(i, a[i], j, a[j]);
	writeln(a[1], ' ', a[2], ' ', a[3], ' ', a[4]);
END.

