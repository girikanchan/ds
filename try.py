import pandas as pd

# Sample Data
data = {
    "Incident_code": [4, 1, 2, 1, 1],
    "Location_start": [999, 92, 100, 92, 211],
    "Location_end": [999, 92, 100, 92, 211],
    "Type_of_incident": [9, 2, 1, 1, 1],
    "terrorists_attack_force": [99, 24, 99, 2, 99],
    "Number_of_nationalities": [1, 1, 9, 9, 9],
    "First_nationality_of_terrorists": [850, 92, 999, 92, 999],
    "Second_nationality_of_terrorists": [998, 999, 999, 999, 999],
    "Third_nationality_of_terrorists": [998, 999, 999, 999, 999],
    "Number_of_nationalities_of_victims": [99, 1, 1, 1, 1],
    "Threats_Carried_Out": [9, 9, 0, 9, 9],
    "Terrorist_Negotiation_Success": [9, 9, 3, 8, 8],
    "Target_Negotiator": [9, 9, 5, 8, 8],
    "Amount_of_Ransom_Paid": [0, 0, 0, 0, 0],
    "Number_of_Prisoners_Released": [0, 999, 0, 0, 0],
    "First_hostage_fate": [99, 2, 14, 10, 98],
    "Second_hostage_fate": [98, 98, 98, 98, 98],
    "Duration_in_Hours": [99, 99, 96, 1, 99],
    "Duration_in_Days": [999, 999, 5, 0, 999],
    "Year": [1, 1, 1, 1, 1]
}

df = pd.DataFrame(data)

def non_dominated_sorting(population_size, chroms_obj_record, objective_name):
    s, n = {}, {}
    front, rank = {}, {}
    front[0] = []
    
    for p in range(population_size * 2):
        s[p] = []
        n[p] = 0
        for q in range(population_size * 2):
            if chroms_obj_record[p][objective_name] > chroms_obj_record[q][objective_name]:
                if q not in s[p]:
                    s[p].append(q)
            elif chroms_obj_record[p][objective_name] < chroms_obj_record[q][objective_name]:
                n[p] = n[p] + 1
        
        if n[p] == 0:
            rank[p] = 0
            if p not in front[0]:
                front[0].append(p)

    i = 0
    while (front[i] != []):
        Q = []
        for p in front[i]:
            for q in s[p]:
                n[q] = n[q] - 1
                if n[q] == 0:
                    rank[q] = i + 1
                    if q not in Q:
                        Q.append(q)
        i = i + 1
        front[i] = Q

    del front[len(front) - 1]
    return front

# Modify the dataset for your specific objective (e.g., "Incident_code")
objective_name = "Incident_code"
chroms_obj_record = df.to_dict(orient='records')

fronts = non_dominated_sorting(len(chroms_obj_record), chroms_obj_record, objective_name)

# Extract the Pareto front
pareto_front = fronts[0]

# Select the chromosome from the Pareto front
selected_chromosome = chroms_obj_record[pareto_front[0]]

print(selected_chromosome)
