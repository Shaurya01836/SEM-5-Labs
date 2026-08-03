# Exp 3:
# Implement the following Attack: a) Dictionary Attack 

import hashlib

# List of commonly used passwords and their variations
common_passwords = ["password", "password123", "letmein", "qwerty", "123456", 
"abc123", "admin", "welcome", "monkey", "sunshine"]

password_variations = ["", "123", "1234", "12345", "123456", "!", "@", "#", "$", "%", "^", 
"&", "*", "(", ")", "-", "_", "+", "=", "/", "\\", "|", "[", "]", "{", "}", "<", ">"]

# Hash of the password to be attacked
hashed_password = hashlib.sha256(b"mypass12#@").hexdigest()
print("Hashed Password is:")
print(hashed_password)


# Try out all possible combinations of common passwords and their variations
for password in common_passwords:
 for variation in password_variations:
  possible_password = password + variation
  hashed_possible_password = hashlib.sha256(possible_password.encode()).hexdigest()
  #print(hashed_possible_password)
  if hashed_possible_password == hashed_password:
   print(f"Password found: {possible_password}")
   break
  else:
   continue
  break
else:
 print("Password not found")