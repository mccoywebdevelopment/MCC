%Christopher McCoy, this program is designed to implement facts in prolog.
male(joseph_kennedyIII).
male(joseph_kennedyII).
male(robert_kennedy).
male(john_kennedy).
male(joseph_kennedy).
male(patrick_kennedy).

female(rose_fitzgerald).
female(jean_kennedy).
female(caroline_kennedy).
female(jacquelin_onassis).
female(mary_kennedy).
female(kathleen_kennedy).

lifespan(joseph_kennedyIII,1980,unknown).
lifespan(joseph_kennedyII,1952,unknown).
lifespan(robert_kennedy,1925,1968).
lifespan(john_kennedy,1917,1963).
lifespan(joseph_kennedy,1888,1969).
lifespan(patrick_kennedy,1949,unknown).

lifespan(rose_fitzgerald,1890,1995).
lifespan(jean_kennedy,1928,unknown).
lifespan(caroline_kennedy,1957,unknown).
lifespan(jacquelin_onassis,1929,1994).
lifespan(mary_kennedy,1954,unknown).
lifespan(kathleen_kennedy,1953,unknown).

%parerntOf(<parent>,<child>).
parentOf(patrick_kennedy,joseph_kennedy).
parentOf(joseph_kennedy,john_kennedy).
parentOf(john_kennedy,caroline_kennedy).
parentOf(robert_kennedy,joseph_kennedyII).
parentOf(joseph_kennedyII,joseph_kennedyIII).
parentOf(robert_kennedy,kathleen_kennedy).
parentOf(robert_kennedy,mary_kennedy).
parentOf(rose_fitzgerald,jean_kennedy).

parentOf(jean_kennedy,unkown).
parentOf(caroline_kennedy,unkown).
parentOf(jacquelin_onassis,caroline_kennedy).
parentOf(mary_kennedy,unkown).
parentOf(kathleen_kennedy,joseph_kennedyIII).


rulerOf(patrick_kennedy,unknown,unknown,unknown).
rulerOf(john_kennedy,usa,1961,1963).
rulerOf(joseph_kennedyIII,unknown,unknown,unknown).
rulerOf(joseph_kennedyII,unknown,unknown,unknown).
rulerOf(joseph_kennedy,unknown,unknown,unknown).
rulerOf(robert_kennedy,unknown,unknown,unknown).
rulerOf(rose_fitzgerald,unknown,unknown,unknown).










