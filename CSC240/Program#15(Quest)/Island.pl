/*
 Christopher McCoy, this program is quest. You start off in the kingdom
 where you summoned by the King. If you choose to accept his quest you
 go to the village where a peasant asks you if he can join you. To
 acoomplish the quest you need to have at least 3 helpers. Then when you
 encounter the dragon you first have to throw a rock to distact him.
 Then if you attack you will defeat the dragon.
*/

start_state(kingdom).

next_state(kingdom,a,you_are_dead):-add_kills.
next_state(kingdom,b,kingdom).
next_state(kingdom,c,get_help).
next_state(kingdom,d,kingdom).
next_state(kingdom,e,you_are_dead).

next_state(get_help,a,mob_attack):-add_kills,stored_answer(kills,Num),check_kills_greater_than_three(Num).
next_state(get_help,a,warning):-add_kills.
next_state(get_help,b,get_help).
next_state(get_help,f,encounter_dragon).
next_state(get_help,c,full_of_helpers):-stored_answer(helpers,Num),check_helpers_greater_than_three(Num).%fix
next_state(get_help,c,get_help):-add_helpers.
next_state(get_help,d,get_help).
next_state(get_help,e,kingdom).
next_state(get_help,f,encounter_dragon).


next_state(full_of_helpers,a,you_are_dead):-add_kills.
next_state(full_of_helpers,b,get_help).
next_state(full_of_helpers,c,get_help).
next_state(full_of_helpers,d,get_help).
next_state(full_of_helpers,e,get_help).

next_state(warning,a,mob_attack):-add_kills,stored_answer(kills,Num),check_kills_greater_than_three(Num).
next_state(warning,a,get_help):-add_kills.
next_state(warning,b,get_help).
next_state(warning,c,get_help).
next_state(warning,d,get_help).
next_state(warning,e,get_help).

next_state(mob_attacks,a,you_are_dead):-add_kills.
next_state(mob_attacks,b,you_are_dead).
next_state(mob_attacks,c,you_are_dead).
next_state(mob_attacks,d,you_are_dead).
next_state(mob_attacks,e,you_are_dead).

next_state(encounter_dragon,a,you_are_dead).
next_state(encounter_dragon,b,dragon_back_turned).
next_state(encounter_dragon,c,you_are_dead).
next_state(encounter_dragon,d,encounter_dragon).
next_state(encounter_dragon,e,get_help).

next_state(dragon_back_turned,a,kill_dragon):-stored_answer(helpers,Num),Num>2,add_kills.
next_state(dragon_back_turned,a,you_are_dead).
next_state(dragon_back_turned,b,you_are_dead).
next_state(dragon_back_turned,c,you_are_dead).
next_state(dragon_back_turned,d,you_are_dead).
next_state(dragon_back_turned,e,encounter_dragon).


%fix
add_helpers:-
	stored_answer(helpers,K),
	OneMoreHelper is K+1,
	retract(stored_answer(helpers,_)),
	asserta(stored_answer(helpers,OneMoreHelper)).
%fix
check_helpers_greater_than_three(Num):-
	Num>3.


%fix
add_kills:-
	stored_answer(kills,K),
	OneMoreKill is K+1,
	retract(stored_answer(kills,_)),
	asserta(stored_answer(kills,OneMoreKill)).
%fix
check_kills_greater_than_three(Num):-
	Num>3.




display_intro :-
	write('You are a knight summoned by King Olaf.'),nl,
	write('There is a dragon eating the peasants of his kingdom.'),nl,
	write('This quest is up to you entirely therefore your actions have serious consequences if you choose unwisely.'),nl,nl.

initialize :-
	asserta(stored_answer(kills,0)),
	asserta(stored_answer(moves,0)),
	asserta(stored_answer(helpers,0)).

goodbye :-
	stored_answer(moves,Count),
	write('You made this many choices...'),
	write(Count),nl,
	
	stored_answer(helpers,Num_helpers),
	write('You had this many helper(s)...'),
	write(Num_helpers),nl,
	
	stored_answer(kills,Num_kills),
	write('You killed '),
	write(Num_kills),nl,
	write('Bye.'),nl,nl.

show_options:-
	write('(a) Slay the person(s) or thing(s) that you encounter.'),nl,
	write('(b) Throw a rock to distract the person(s) or thing(s) that you encounter.'),nl,
	write('(c) Accept what the person(s) or thing(s) said.'),nl,
	write('(d) Look away from the person(s) or thing(s).'),nl,
	write('(e) Go back to previos location.'),nl,nl.



show_state(kingdom):-
	nl,nl,
	write('Inside the castle with the King'),nl,
	write('He begs you to kill the dragon before the kingdom is engulfed by flames.'),nl,nl,
	show_options,nl,nl.

show_state(get_help):-
	write('Inside the village'),nl,
	write('A peasant from the village offers to help you on your quest.'),nl,nl,
	write('(a) Slay the person(s) or thing(s) that you encounter.'),nl,
	write('(b) Throw a rock to distract the person(s) or thing(s) that you encounter.'),nl,
	write('(c) Accept what the person(s) or thing(s) said.'),nl,
	write('(d) Look away from the person(s) or thing(s).'),nl,
	write('(e) Go back to previos location.'),nl,
	write('(f) Travel to the dragons lair.'),nl,nl.	

show_state(full_of_helpers):-
	write('You dont have enough supplies and patience to add another peasant to the group.'),nl,nl,
	show_options,nl,nl.

show_state(warning):-
	stored_answer(kills,Count),
	write('You killed '),
	write(Count),
	write(' so far, knock it off!'),nl,nl,
	show_options,nl,nl.


show_state(mob_attack):-
	write('You killed another peasant!'),nl,
	write('You shall die for your bretrayal!!!!'),nl,nl.

show_state(encounter_dragon):-
	write('Dragon: MMmm care to join the other victims in my belly?'),nl,
	write('You reach the cave where the dragon resides after eating a peasant snack.'),nl,
	write('Kill it if you dare...'),nl,nl,
	show_options,nl,nl.

show_state(dragon_back_turned):-
	write('Dragon: Where did you go?'),nl,
	write('It worked!!! The dragon is distracted by the rock you threw.'),nl,
	write('Kill it if you dare...'),nl,nl,
	show_options,nl,nl.

%automatically get a q 
show_state(kill_dragon):-
	write('You killed the dragon with help of the peasants yeeeeaaaaahhhh!!!'),nl,nl.

show_state(you_are_dead):-
	write('Good try but not good enough you are dead and so is the rest of the people in the village.'),nl,
	write('HINT: Try not to kill so many of the peasants and maybe you can use them to help you destroy the dragon.'),nl,nl.


% kingdom=================================================================

show_transition(kingdom,a):-
	write('Great, you killed you did that exact opposite what he wanted to do.'),nl,
	write('Killing a King is a result in death!'),nl,nl.

show_transition(kingdom,b):-
	write('King: Why in the world did you throw a rock at my son!?!'),nl,nl.

show_transition(kingdom,c):-
	write('King: Thank you so much for accepting the quest.'),nl,nl.

show_transition(kingdom,d):-
	write('King: My eyes are over here....'),nl,
	write('King: (Whispers) I wish I had knights with higher IQs.'),nl,nl.
%Maybe add q
show_transition(kingdom,e):-
	write('King: What!?! You just got here!'),nl,nl,
	write('You traveled home and on the way home you were killed by lightning.'),nl,nl.

% get_help================================================================
show_transition(get_help,a):-
	write('Someone is a bit blood thirsty...'),nl,
	write(''),nl,nl.

show_transition(get_help,b):-
	write('peasant: Nice throw.'),nl,nl.

show_transition(get_help,c):-
	write('peasant: Will I be payed with a virgin if I slay the dragon?'),nl,nl.

show_transition(get_help,d):-
	write('Peasant: I know i may be ugly but hey you are not so good looking too.'),nl,nl.
	
%Maybe add q
show_transition(get_help,e):-
	write('Back to the kingdom you shall...'),nl,nl.
show_transition(get_help,f):-
	write('You traveled many miles....'),nl,nl.

% full_of_helpers=========================================================
show_transition(full_of_helpers,a):-
	write('Killing them off wont solve the problem.'),nl,
	write(''),nl,nl.

show_transition(full_of_helpers,b):-
	write('peasant(s): Nice throw.'),nl,nl.

show_transition(full_of_helpers,c):-
	write('You cant have anymore helpers the village needs them for other stuff.'),nl,nl.

show_transition(full_of_helpers,d):-
	write('peasant:...ok'),nl,nl.
	
%Maybe add q
show_transition(full_of_helpers,e):-
	write(''),nl,nl.
% warning=================================================================
show_transition(warning,a):-
	write('peasant: Someone didnt get played enough when they were a child. '),nl,
	write(''),nl,nl.

show_transition(warning,b):-
	write('peasant(s): Nice throw.'),nl,nl.

show_transition(warning,c):-
	write('peasant: Thank god he agreed I thought we were going to have to kill you.'),nl,nl.

show_transition(warning,d):-
	write('peasant: Thats right look away you pig.'),nl,nl.
	
%Maybe add q
show_transition(warning,e):-
	write('peasant: You better go back to where you came from.'),nl,nl.
% encounter_dragon========================================================
show_transition(encounter_dragon,a):-
	write('You and peasant(s): CHARCH!!!!! LALALALA......'),nl,
	write(''),nl,nl.

show_transition(encounter_dragon,b):-
	write('*clink* (dragon looks away)'),nl,
	write('peasant: Should we charge?'),nl,nl.

show_transition(encounter_dragon,c):-
	write('You voluntarly walk into the dragons mouth.'),nl,nl.

show_transition(encounter_dragon,d):-
	write('Looking away wont make your problems disapear come man pick up that sword and do some business.'),nl,nl.
	
%Maybe add q
show_transition(encounter_dragon,e):-
	write('peasant: whew... I thought we were done for.'),nl,nl.
% dragon_back_turned======================================================
show_transition(dragon_back_turned,a):-
	write('You and peasant(s): CHARCH!!!!! LALALALA......'),nl,
	write(''),nl,nl.

show_transition(dragon_back_turned,b):-
	write('*clink* (dragon looks turns back and finds you)'),nl,
	write('Oppps'),nl,nl.

show_transition(dragon_back_turned,c):-
	write('You: We are right here you big dumbo!'),nl,
	write('(dragon turns around and kills you)'),nl,nl.

show_transition(dragon_back_turned,d):-
	write('You looked away and the dragon eventually found out where you were hiding.'),nl,nl.
	
%Maybe add q
show_transition(dragon_back_turned,e):-
	write('peasant: whew... I thought we were done for.'),nl,nl.



% IMPORTANT===============================================================
% =======================================================================
get_choice(kill_dragon,q).
get_choice(you_are_dead,q).
% ========================================================================
% =======================================================================


% basic finite state machine engine
get_choice(_,C) :-
    write('Next entry (letter followed by a period)? '),nl,nl,nl,nl,nl,
    read(C).

go :-
	intro,
	start_state(X),
	show_state(X),
	get_choice(X,Y),
	go_to_next_state(X,Y).

intro :-
	display_intro,
	clear_stored_answers,
	initialize.

go_to_next_state(_,q) :-
	goodbye,!.

go_to_next_state(S1,Cin) :-
	next_state(S1,Cin,S2),
	show_transition(S1,Cin),
	show_state(S2),
	stored_answer(moves,K),
	OneMoreMove is K + 1,
	retract(stored_answer(moves,_)),
	asserta(stored_answer(moves,OneMoreMove)),
	get_choice(S2,Cnew),
	go_to_next_state(S2,Cnew).

go_to_next_state(S1,Cin) :-
	\+ next_state(S1,Cin,_),
	show_transition(S1,fail),
	get_choice(S1,Cnew),
	go_to_next_state(S1,Cnew).


% case knowledge base - user responses

:- dynamic(stored_answer/2).

% procedure to get rid of previous responses
% without abolishing the dynamic declaration

clear_stored_answers :- retract(stored_answer(_,_)),fail.
clear_stored_answers.

:- go.







