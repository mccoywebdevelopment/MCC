%Christopher McCoy, this program is an example of a decision tree
% representing the choices the Trojans could have made when they
% encountered the Trojan horse.

start_game:-
intro,
write('Answer all questions y for yes or n for no.'),nl,
clear_stored_answers,
try_all_possibilities.

try_all_possibilities:-
may_be(D),
explain(D),
fail.

try_all_possibilities.

:- dynamic(stored_answer/2).

clear_stored_answers :- retract(stored_answer(_,_)),fail.
clear_stored_answers.

user_says(Q,A):- stored_answer(Q,A).

user_says(Q,A):-
    \+ stored_answer(Q,_),
    nl,nl,
    ask_question(Q),
    get_yes_or_no(Response),
    asserta(stored_answer(Q,Response)),
    Response=A.

get_yes_or_no(Result):-
    get(Char),
    get0(_),
    interpret(Char,Result),
    !.

get_yes_or_no(Result):-
    nl,
    write('Type y or n'),
    get_yes_or_no(Result).

interpret(89,yes).
interpret(121,yes).
interpret(78,no).
interpret(110,no).

intro:-
write('this program is an example of a decision tree representing the choices'),nl,
write('the Trojans could have made when they encountered the Trojan horse.'),nl.

ask_question(horse):- write('Is it a wooden horse?').
ask_question(wheels):- write('Does it have wheels?').
ask_question(noises):- write('Does it have suspicious noices coming'),nl,
write('inside it?').
ask_question(machine):- write('Can you make some sort of machine'),nl,
write('that can pull it back to Troy?').
ask_question(inside):- write('Do you want to bring it inside the city'),nl,write('of Troy so we can celebrate out victory!').

explain(not_a_horse):- nl,
write('Its probably a horse that is alive that you can'),nl,
write('ride back to Troy.').
explain(lot_of_work):- nl,
write('Probably should just go home because that would'),nl,
write('be a lot to work to just drag it to the city.').
explain(party_foul):- nl,
write('Dude that was such a party foul and'),nl,
write('as a result you are lame forever bro.').
explain(oops):-write('Oops it turns out that the enemy was hiding'),nl,
write('inside the wooden horse. As a result they open the gates'),nl,
write('and took control over the city of Troy hope no one ever'),nl,
write('writes about this embarrassing story.').
explain(yay):- write('CONGRATULAIONS!!! You found the Greek elite'),nl,
write('force hiding inside the wooden horse.'),nl,
write('Leave it!Dont bring it inside the gates!').
explain(message):-
write('Lets send a message to the Greeks telling them they forgot'),nl,
write('their stuff.').

may_be(message):-
user_says(horse,yes),
user_says(wheels,yes),
user_says(noises,no).

may_be(not_a_horse):-
user_says(horse,no).

may_be(lot_of_work):-
user_says(horse,yes),
user_says(wheels,no),
user_says(machine,no).

may_be(party_foul):-
user_says(horse,yes),
user_says(wheels,no),
user_says(machine,yes),
user_says(inside,no).

may_be(oops):-
user_says(horse,yes),
user_says(wheels,no),
user_says(machine,yes),
user_says(inside,yes).

may_be(yay):-
user_says(horse,yes),
user_says(wheels,yes),
user_says(noises,yes).








