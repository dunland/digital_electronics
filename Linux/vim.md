## Execution

- **Force Exit**: `:q!`
- **Write Changes**: `:w`

- **Undo last command**: `u`
- **Undo entire line**: `U` (togglen durch wiederholtes Drücken)

## Editing

- **Deletion**
	- **Delete Character**: `x`
	- **Delete Word** until start of next word: `dw`
	- **Delete Word** until end of current word: `de`
	- **Delete n words**: `d2w`, `d3e`, etc.
	- **Delete to the end of line**: `d$`
	- **Delete entire line:** `dd`
- **Insert Character**:
	- `i` – Text vor Cursor
	- `I` – Text an Zeilenanfang
- **Append Character**: 
	- `a` – Text hinter Cursor
	- `A` – Text an Zeilenende
- **Replace** character by another: `re` – ersetzt aktuellen Buchstaben durch *e*
	- **change** until end of word: `ce` – dann Text eingeben und mit `Escape` zurück
- **Put** previously deleted text: `p`

## Navigation
- `h, j, k, l`: links, unten, oben, rechts
- `w`: gehe zu **nächstem Wortanfang**
- `e` gehe zum **Ende des aktuellen Wortes**
- `0` gehe zu **Zeilenanfang**