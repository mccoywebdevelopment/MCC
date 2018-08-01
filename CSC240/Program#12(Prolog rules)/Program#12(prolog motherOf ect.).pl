%Christopher McCoy, this program is an example of how to determine information from a database.

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

lifespan(joseph_kennedyIII,1980,_).
lifespan(joseph_kennedyII,1952,_).
lifespan(robert_kennedy,1925,1968).
lifespan(john_kennedy,1917,1963).
lifespan(joseph_kennedy,1888,1969).
lifespan(patrick_kennedy,1949,_).

lifespan(rose_fitzgerald,1890,1995).
lifespan(jean_kennedy,1928,_).
lifespan(caroline_kennedy,1957,_).
lifespan(jacquelin_onassis,1929,1994).
lifespan(mary_kennedy,1954,_).
lifespan(kathleen_kennedy,1953,__).

%parerntOf(<parent>,<child>).
parentOf(patrick_kennedy,joseph_kennedy).
parentOf(joseph_kennedy,john_kennedy).
parentOf(john_kennedy,caroline_kennedy).
parentOf(robert_kennedy,joseph_kennedyII).
parentOf(joseph_kennedyII,joseph_kennedyIII).
parentOf(robert_kennedy,kathleen_kennedy).
parentOf(robert_kennedy,mary_kennedy).
parentOf(rose_fitzgerald,jean_kennedy).
parentOf(joseph_kennedy,robert_kennedy).
parentOf(rose_fitzgerald,robert_kennedy).


rulerOf(patrick_kennedy,_,_,_).
rulerOf(john_kennedy,usa,1961,1963).
rulerOf(joseph_kennedyIII,_,_,_).
rulerOf(joseph_kennedyII,_,_,_).
rulerOf(joseph_kennedy,_,_,_).
rulerOf(robert_kennedy,_,_,_).
rulerOf(rose_fitzgerald,_,_,_).

motherOf(Mom,Child):-
	female(Mom),
	parentOf(Mom,Child).

fatherOf(Dad,Child):-
	male(Dad),
	parentOf(Dad,Child).

sonOf(Son,Parent):-
	male(Son),
	parentOf(Parent,Son).

duaghterOf(Daughter,Parent):-
	female(Daughter),
	parentOf(Parent,Daughter).

brotherOf(Brother, Sibling):- 
	male(Brother),
       	siblingOf(Brother, Sibling).

sisterOf(Sister, Sibling):- 
	female(Sister),
       	siblingOf(Sister, Sibling).

siblingOf(Sibling1,Sibling2):-
	\+ Sibling1=Sibling2,
	parentOf(Parent,Sibling1),
	parentOf(Parent,Sibling2).

auntOf(Aunt, Person)
    :- female(Aunt),
       parentOf(Parent, Person),
       siblingOf(Aunt, Parent).


grandparentOf(Grandparent, Grandchild):- 
	parentOf(Parent, Grandchild),
       	parentOf(Grandparent, Parent).

descendantOf(Descendent,Ancestor):-
	ancestorOf(Ancestor, Descendent).

ancestorOf(Ancestor,Descendent):-
	parentOf(Ancestor, Descendent);
       (motherOf(Mother, Descendent),
        ancestorOf(Ancestor, Mother));
       (fatherOf(Father, Descendent),
        ancestorOf(Ancestor, Father)).

bornDuringLifeOf(Person, Other) :-
    lifespan(Person, BirthYear, _),
    integer(BirthYear),
    lifespan(Other, OtherBirthYear, OtherDeathYear),
    integer(OtherBirthYear),
    integer(OtherDeathYear),
    BirthYear >= OtherBirthYear,
    BirthYear =< OtherDeathYear.

contemporaryOf(Contemporary, Person) :-
    bornDuringLifeOf(Contemporary, Person);
    bornDuringLifeOf(Person, Contemporary).

successorOf(Successor, Person) :-
    rulerOf(Successor, Country, SuccessorBeganYear, _),
    integer(SuccessorBeganYear),
    rulerOf(Person, Country, _, PersonEndYear),
    integer(PersonEndYear),
    SuccessorBeganYear == PersonEndYear.

	


aaa(X):-
	male(X), \+ lifespan(X,_,_).










