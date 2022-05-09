def is_unique_with_additional_data_structures(s):
    seen = set()
    for char in s:
        if char in seen:
            return False
        seen.add(char)
    return True


def is_unique_with_no_additional_data_structures(s):
    for i in range(len(s)):
        for j in range(len(s)):
            if i == j:
                continue
            if s[i] == s[j]:
                return False
    return True


cases = [
    ("a", True),
    ("abc", True),
    ("abca", False),
    ("aabcd", False),
]

for c in cases:
    assert is_unique_with_additional_data_structures(c[0]) == c[1], c[0]
    assert is_unique_with_no_additional_data_structures(c[0]) == c[1], c[0]
