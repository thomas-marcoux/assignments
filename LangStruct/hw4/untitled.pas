{
   untitled.pas
   
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

var j: integer;
a: array[1..4] of integer;

{procedure q(var x : integer; var i: integer);}
procedure q(x, i: integer);
	var j : integer;
	BEGIN
		j := 2;
		i := 4;
		x := x+i;
		a[1] := 8;
		i := 3;
		x := x+j;
	END;
	
BEGIN
	a[1] := 1;
	a[2] := 2;
	a[3] := 3;
	a[4] := 4;
	j := 1;
	q(a[j], j);
	writeln(a[1], ' ', a[2], ' ', a[3], ' ', a[4]);
END.

