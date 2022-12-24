# first_set={"apple","grapes","berry","apple"}
# print(first_set)

# first_set={"apple","grapes","berry"}
# print(type(first_set))

# first_set=set(("apple","grapes","berry"))
# print(first_set)

# languages=set(("C++","Java","C#","PHP","JavaScript"))
languages = { "C++", "Java", "C#", "PHP", "JavaScript" }
# languages = languages | { "Python" }
languages=languages.union({"python"})
print(languages)
