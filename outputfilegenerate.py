import os

# Assuming all your files are in the 'source_folder'
source_folder = '/Users/spartan/Documents/SJSU/Sem2/CMPE-202/Assignments/Assignment-3/CMPE-202-Assignment-3'
files = [
    "ComputerPlayer.cpp", "ComputerPlayer.h", "GameChoice.cpp",
    "GameChoice.h", "GameChoiceService.h", "GameChoiceServiceImpl.h",
    "GameEngine.cpp", "GameEngine.h", "HumanPlayer.cpp", "HumanPlayer.h",
    "PatternPredictor.cpp", "PatternPredictor.h", "Player.h", "RockPaperScissorsGame.cpp",
    "RockPaperScissorsGame.h", "main.cpp"
]

# The name of the new file where you want to merge all the content
output_file_path = '/Users/spartan/Documents/SJSU/Sem2/CMPE-202/Assignments/Assignment-3/CMPE-202-Assignment-3/merged_files.txt'

with open(output_file_path, 'w') as outfile:
    for fname in files:
        with open(os.path.join(source_folder, fname)) as infile:
            # Optional: Write the name of the file being read
            outfile.write(f"----- Content of {fname} -----\n")
            # Write the content of the file to the outfile
            outfile.write(infile.read())
            # Optional: Write a newline after each file's content
            outfile.write("\n")

print(f"All files have been merged into {output_file_path}")