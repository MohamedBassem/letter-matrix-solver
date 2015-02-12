# Letter Matrix Solver
A c++ letter matrix solver using tries and Unix word list.

## How to make it work

1- Clone the repo.

2- Make and run the executable `main`.

3- Make sure that the input matrix doesn't contain spaces.

4- Output is printed to stdout.

## How it works
1- It loads the Unix word list - `/usr/share/dict/words` - in memory in a Trie.

2- For each index in the matrix words formed horizontally, vertically and diagonally - of length at least 3 and at most the maximum length in the trie - are searched for in the Trie.

3- Matches are added to a set to remove duplicates.

Given that the search in a trie takes at most length of longest word in dictionary iterations which is constant. The overall complexity of solving the letter matrix is O(N^2) with a constant factor of ~100 - assuming that the longest word in the dictionary is 10 characters long - and with a pre-computation to the dictionary which takes linear time.

To learn more about tries read this [Topcoder tutorial](http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=usingTries).

## Example

An Example using one of [Medium's #wordsearchwednesday](https://medium.com/@Medium/wordsearchwednesday-a519722b5afd).

```bash
$ make
g++ ./src/Trie.cpp ./src/LetterMatrixSolver.cpp ./src/Main.cpp ./src/Util.cpp -o main -std=c++11
$ time ./main
30
AEUPHEMISMPAOAM
ENUUSETOLPPXNDD
TNAZAIOAKHYTSAP
WYKCRESMOMIJLEN
WGIOHSRROTBLGXS
XONNQRIRHTEEYPY
EYGNZSOEZGILGON
RCNOMNSNOAPFASO
OTNTJICRIPALIIP
HTHASMYYMSLDHTS
PNUTNJZOYIMEBII
AEJICONNTNPNAOS
TTIOQOSEBAEOSNF
ENANLMRSCRRTOAK
MOQOGASZARSALNZ
PCGRTMERTAOTIET
LUFIILVEHTNILCH
EFOIISOTAIIOODE
CNAMAOAERVFNQOS
AIIIKPZMSEIEUTI
CSKLEJDMIGCHYES
OVHSDOKISTACVYE
PJUXTAPOSITIONH
HCLIMAXOECILFMT
OTEHTIPETSOCPCO
NISARCASMANUTZP
YAZCONTEXTMKRXY
VRAMBIGUITYOPSH
ANVODNEUNNIPNME
SYNECDOCHEUSAOU
228
ABE
ACE
ADA
AGO
AKIN
ALI
AMBIGUITY
ANECDOTE
ANI
ANT
ARC
ASH
ATE
ATONE
ATONED
ATS
BIG
CACOPHONY
CAT
CATHARSIS
CATION
CATS
CHE
CHEN
CLIMAX
CLINT
COD
CON
CONN
CONNOTATION
CONTENT
CONTEXT
COP
COST
DEN
DENOTATION
DOC
DOT
DOTE
ELF
ELK
ELKS
END
EPITHET
ERR
ETA
EUPHEMISM
EVITA
EXPO
EXPOS
EXPOSITION
FIN
GAP
GAPS
GAS
GEO
GIL
HAS
HEM
HEN
HES
HON
HOOK
HYPO
HYPOTHESIS
IBM
ICE
ICON
ILA
INA
INC
IND
ING
INN
INNUENDO
INS
ION
IRON
ISM
ITO
JIM
JUXTAPOSITION
KIN
KING
LAP
LEN
LES
LICE
LICHEN
LIMA
LIN
LINT
LOT
MAN
MAO
MAR
MAX
MET
METAPHOR
METE
METER
MIG
MIL
MILCH
MILS
MIN
MOE
MOM
MOMS
MON
MOO
MRS
NAM
NAN
NARRATIVE
NED
NET
NIL
NIP
NIX
NOH
NOR
NOT
NOTATION
NTH
NUT
OAK
OAT
ODE
OHS
ONE
ONES
ONO
ORE
ORR
PAL
PALM
PAS
PAST
PASTY
PAT
PATE
PER
PERSON
PERSONIFICATION
PET
PETS
PHONY
PIE
PIN
PIT
PITH
PLOT
PONY
POSIT
POSITION
POT
QOM
RAM
RAN
RASH
RAT
RCA
REP
REX
RIO
RIOS
RIP
ROB
RON
ROT
SAC
SAG
SAGO
SAL
SAP
SARCASM
SAT
SEN
SET
SIN
SIS
SIT
SLIM
SOL
SOLI
SOLILOQUY
SON
SOP
SOT
SPA
STEP
STY
SUE
SYNOPSIS
TAO
TAP
TAR
TAT
TEA
TEE
TEMP
TEMPLE
TEN
TENT
TESS
TEX
TEXT
THAR
THE
THESIS
TIA
TIC
TICS
TIE
TIP
TOD
TON
TONE
TONED
TOP
TOR
TUN
TUNA
USE
YES
YET
YON

real    0m0.059s
user    0m0.059s
sys     0m0.000s
```
Using a better dictionary will lead to better results without affecting the complexity.
