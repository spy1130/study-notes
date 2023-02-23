def bin1(dec):
    result = ''

    if dec:
        result =bin1(dec//2)
        return result + str(dec%2)
    else:
        return result

print(bin1(62))