"""
tasks format should be:
	1. task id - with depended out and in
	2. test ins ( preloaded or generate in randomly)
	3. test outs - calculate once of write code to compare
	4. run options - how to run it on java/python/etc
"""
import subprocess
import logging
import collections 

def run_py(filepath, inputs):
	res = []
	for item in inputs:
		main_process = subprocess.Popen(["python3", filepath],
		stdin = subprocess.PIPE,
		stdout = subprocess.PIPE,
		stderr = subprocess.PIPE)
		out, err = main_process.communicate(bytes(item, "utf-8"))
		if not main_process.returncode == 0:
			print(err.decode('utf=8'))
			return None
		res.append(out.decode('utf-8'))
	return res

class task:
	def __init__(self, task_id, inputs, outputs):
		self.task_id = task_id
		self.inputs = inputs
		self.outputs = outputs


	def run_test(self, filepath):
		lang_postfix = filepath.split(".")[-1] 
		if lang_postfix == "py":
			prog_out = run_py(filepath, self.inputs)
			for item1, item2 in zip(prog_out, self.outputs):
				if not collections.Counter(item1.split("\n")) == collections.Counter(item2.split("\n")):
					return False
			return True
		else:
			logging.error(f"no such lang as {lang_postfix} supported")
			return False

test_task = task(123, ["1\n2"], ["1\n4\n"])

print(test_task.run_test("./test_script.py"))



