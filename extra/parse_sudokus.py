import os

for file_path in os.listdir("tests/sudokus"):
    text = ""
    with(open("tests/sudokus/"+file_path,"r")) as f:
        text = " ".join([line.replace(" ","").replace("\n","") for line in f])
    with(open("tests/sudokus/"+file_path,"w")) as f: 
        f.write(text)