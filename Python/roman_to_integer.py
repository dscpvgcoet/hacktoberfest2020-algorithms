def roman_to_int(roman: str) -> int:

    vals = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
    total = 0
    place = 0
    while place < len(roman):
        if (place + 1 < len(roman)) and (vals[roman[place]] < vals[roman[place + 1]]):
            total += vals[roman[place + 1]] - vals[roman[place]]
            place += 2
        else:
            total += vals[roman[place]]
            place += 1
    return total

CLIV = "CLIV"
III = "III"

print("Test 1: CLIV -> "+str(roman_to_int(CLIV)))
print("Test 2: III -> "+str(roman_to_int(III)))
