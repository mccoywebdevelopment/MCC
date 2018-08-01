friends(jerry,george).
friends(jerry,kramer).
friends(kramer,newman).
professionOf(jerry,comediam).
professionOf(george,plumber).
professionOf(kramer,unknown).
professionOf(newman,mailman).
highestScore(jerry,98).
highestScore(george,12).
highestScore(kramer,3.12).
highestScore(newman,59).

skillfulFriendlyPlumberOf(Person,Plumber):-
    professionOf(Plumber,plumber),
    friends(Person,Plumber),
    highestScore(Person,X),
    X>=50.


