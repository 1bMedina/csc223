commands = {
    "MOV A,B": "170", "MOV B,A": "107", "MOV B,C": "100",
    "MVI A": "076", "MVI B": "006", "MVI C": "016",
    "ADD B": "200", "SUB B": "220",
    "DCR A": "075", "JMP": "303", "HLT": "166",
    'CALL': '315', 'PUSH B': '305', 'POP B': '301',
    'LDA': '072', 'STA': '062'
}

def switches_visual(octal_string):
    nums = octal_string.split()
    for num in nums:
        binary = bin(int(num, 8))[2:].zfill(8)
        print(f'  {binary[:2]} {binary[2:5]} {binary[5:]}')
        print(f'  {' '.join(['□' if b=='0' else '▣' for b in binary])}')
        print()

print('\nAltair 8080 Command Visualization')
print(f'Available Commands:  {list(commands.keys())}')

while True:
    user_cmd = input('Enter Desired Command> ').strip().upper()
    if user_cmd == 'EXIT': break
    
    if user_cmd.startswith('MVI'):
        octal = commands['MVI ' + user_cmd[4]] + ' ' + user_cmd[6:8]
    else:
        octal = commands.get(user_cmd, '?')
    
    if octal == '?':
        print('Unknown command')
        continue
    
    print(f'\nVisualization of {user_cmd}')
    print('-' * 40)
    print(f'Octal: {octal}')
    print("Switches Key: □ = OFF (0)  ▣ = ON (1)")
    print('\n')
    switches_visual(octal)