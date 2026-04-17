def remove_duplicates(data_list):
    result = []
    for item in data_list:
        if item not in result:
            result.append(item)
    return result

def strip_whitespaces(string_list):
    result = []
    for item in string_list:
        result.append(item.strip())
    return result