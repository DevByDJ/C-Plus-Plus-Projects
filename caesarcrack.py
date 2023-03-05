from string import printable
if __name__ == "__main__":
    
    
    #phrase:{'key': 'value', 'file': 'txt', 'number': 1}
    phrase = "8>xrL>{c>InyHr>]c>svyr>{c>GKG>]c>AHzorE>{cea" # encrypted with key 13
    key = 13
    mode = 'd' # e = encrypt, d = decrypt
    codex = printable.strip()
    codex += " "
    
    #phrase: This is my secret message.
    phrase = '"pqA7qA7uG7AmkzmB7umAAiom@' # encrypted with key 8
    key = 8
    mode = 'd' # e = encrypt, d = decrypt
    codex = printable.strip()
    codex += " "
    

    #phrase: My secret is a secret (you cannot know it!).
    phrase = 'XJaDpnCpEatDalaDpnCpEa=JzFanlyyzEavyzHatE,>]' # encrypted with key 11
    key = 11
    mode = 'd' # e = encrypt, d = decrypt
    codex = printable.strip()
    codex += " "

    #phrase = There once was a pineapple under the sea.
    phrase = ")wtGteDCrteLpHepeExCtpEEAteJCstGeIwteHtp{" # encrypted with key 15
    key = 15
    mode = 'd' # e = encrypt, d = decrypt
    codex = printable.strip()
    codex += " "

    #phrase = This is a short one.
    phrase = ",zAKhAKhshKzGJLhGFw~" # encrypted with key 18
    key = 18
    mode = 'd' # e = encrypt, d = decrypt
    codex = printable.strip()
    codex += " "

    #phrase = Aren't you a little short to be a stormtrooper?
    phrase = "Bsfo(u0zpv0b0mjuumf0tipsu0up0cf0b0tupsnusppqfs@" # encrypted with key 1
    key = 1
    mode = 'd' # e = encrypt, d = decrypt
    codex = printable.strip()
    codex += " "

    #phrase = This is the final, really?!, message. (I think!)
    phrase = "*xyIfyIfJxufvyDqB`fHuqBBO3;`fCuIIqwu|f\YfJxyDA;]" # encrypted with key 16
    key = 16
    mode = 'd' # e = encrypt, d = decrypt
    codex = printable.strip()
    codex += " "
    
    
    transformed = ""
    for token in phrase:
        # check if valid symbol and where its index is
        if token in codex:
            tokenidx = codex.find(token)
            #print(tokenidx) # uncomment to check
            # Perform either encryption or decryption (change this to check your work)
            # this is the main encryption so when "hacking" think - how could I check all of them?
            # Handle any wraparound (using % operator)
            if mode == 'e':
                transformidx = (tokenidx + key) % len(codex)
            else:
                transformidx = (tokenidx - key) % len(codex)
            transformed += codex[transformidx]
        else:
            # technically could have a unicode char or something so we'll just append that raw
            transformed += token

    print(transformed)