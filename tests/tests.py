import yaml

with open("config.yml", "r") as ymlfile:
    cfg = yaml.load(ymlfile)

sudents = cfg["students"] 

"""
tasks format should be:
	1. task id - with depended out and in
	2. test ins ( preloaded or generate in randomly)
	3. test outs - calculate once of write code to compare
	4. run options - how to run it on java/python/etc
"""
