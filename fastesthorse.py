from random import sample

print('\n\t Our available Horses:')
horses = sample(range(1,26), 25)
winner = [] * 3
print(horses)

print('\n\t 5 Groups of 5 Horses:')
races=5
length = len(horses)
horses = [ horses[i*length // races: (i+1)*length // races] for i in range(races) ]
print(*horses)

print('\n\t First 5 Races:')
horses[0].sort()
horses[1].sort()
horses[2].sort()
horses[3].sort()
horses[4].sort()
print(*horses)

print('\n\t Race 6: The fastest Horse of each Group. Keep the best 3 Groups')
horses.sort()
horses = horses[:3]
print(*horses)

print('\n\t Now it gets a bit complicated. We need the 3 fastest Horses so we must keep the first 3 Horses in every Group:')
for i in range(3):
    horses[i] = horses[i][:3]
print(horses)

print('\n\t We also know that the fastest Horse is in Group 1 at Position 1. We can add it as our winner.')
winner.append(horses[0].pop(0))

print('\t Horse 3 of Group 2 and Horses 2,3 from Group 3 can be deleted which leaves us with 5 Horses left for the final Race.')
horses[1] = horses[1][:2]
horses[2] = horses[2][:1]
horses[0].extend(horses[1])
horses[0].extend(horses[2])
horses = horses[0]
print(horses)

print('\n\t With the 7th Race we just get the 2 best Horses and add them to our "winner" of Race 6 at place 2 and 3.')
horses.sort()
winner.append(horses.pop(0))
winner.append(horses.pop(0))
print(winner)