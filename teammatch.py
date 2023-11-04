from itertools import combinations

# Function to calculate net run rate (NRR) for a match
def calculate_nrr(runs1, balls1, runs2, balls2):
    rr1 = ((runs1 - runs2) * 2) / balls2
    rr2 = ((runs2 - runs1) * 2) / balls1
    return rr1, rr2

# Parse input data
results = []
for _ in range(54):
    match_result = input().split()
    results.append(match_result)

rankings = []
for _ in range(8):
    team_ranking = input()
    rankings.append(team_ranking)

# Calculate points and NRR for each team based on the provided results
teams_data = {}
for match_result in results:
    team1, result1, team2, result2 = match_result[0], match_result[1], match_result[2], match_result[3]
    runs1, wickets1, balls1 = map(int, result1.split('/'))
    runs2, wickets2, balls2 = map(int, result2.split('/'))

    rr1, rr2 = calculate_nrr(runs1, balls1, runs2, balls2)

    if team1 not in teams_data:
        teams_data[team1] = {'points': 0, 'nrr': 0}
    if team2 not in teams_data:
        teams_data[team2] = {'points': 0, 'nrr': 0}

    if runs1 > runs2:
        teams_data[team1]['points'] += 2
        teams_data[team1]['nrr'] += rr1
        teams_data[team2]['nrr'] += rr2
    elif runs2 > runs1:
        teams_data[team2]['points'] += 2
        teams_data[team2]['nrr'] += rr2
        teams_data[team1]['nrr'] += rr1
    else:
        teams_data[team1]['points'] += 1
        teams_data[team2]['points'] += 1

# Identify teams that have played only 13 matches
remaining_teams = [team for team in teams_data if teams_data[team]['points'] < 14]

# Generate all possible combinations of teams for the remaining two matches
possible_outcomes = []
for combination in combinations(remaining_teams, 2):
    match1 = (combination[0], combination[1])
    match2 = (combination[1], combination[0])
    possible_outcomes.append([match1, match2])

# Check the outcomes of the remaining matches and consider valid outcomes
valid_outcomes = []
for outcome in possible_outcomes:
    temp_teams_data = {team: data.copy() for team, data in teams_data.items()}

    for match in outcome:
        team1, team2 = match
        temp_teams_data[team1]['points'] += 2
        temp_teams_data[team1]['nrr'] += 0  # NRR does not change for tied matches
        temp_teams_data[team2]['nrr'] += 0

    # Sort the teams based on points and NRR
    sorted_teams = sorted(temp_teams_data.keys(), key=lambda team: (-temp_teams_data[team]['points'], -temp_teams_data[team]['nrr'], team))
    
    # Check if there are changes in the rankings
    if sorted_teams != rankings:
        valid_outcomes.append(outcome)

# Print the valid outcomes in lexicographical order
for outcome in valid_outcomes:
    match1, match2 = outcome
    print(f"WIN:{match1[0]}|LOSE:{match1[1]}||WIN:{match2[0]}|LOSE:{match2[1]}")
