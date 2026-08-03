# Exp 1:
# Implement the following Substitution & Transposition Techniques concepts:
# a) Caesar Cipher 

def encrypt_fun(text,shift):
 result = ""
 
 for i in range(len(text)):
  character = text[i]
  # Encrypt uppercase characters
  if (character.isupper()):
   result += chr((ord(character) + shift-65) % 26 + 65)
  # Encrypt lowercase characters
  else:
   result += chr((ord(character) + shift - 97) % 26 + 97)
 return result


text = "CaesarCipher"

shift = 3

print ("Text : " + text)
print ("Shift : " + str(shift))
print ("Cipher: " + encrypt_fun(text,shift))