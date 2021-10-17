import unittest
import os
import json
from gradescope_utils.autograder_utils.json_test_runner import JSONTestRunner
from test_generator import find_data_directories, build_test_class, TestMetaclass

if __name__ == '__main__':
    #suite = unittest.TestSuite()
    #parent_suite=suite
    # check for suites
    parent_suite = None
    for root, dirs, files in os.walk('./test_data', topdown=True):
        new_suite = unittest.TestSuite();
        if parent_suite is not None:
            parent_suite.addTest(new_suite);
        else:
            suite = new_suite
        # if we're in a bottom level and have a run.sh file to execute
        if 'run.sh' in files:
            test_dir = os.path.relpath(root, './test_data')
            klass = build_test_class(test_dir)
            new_suite.addTest(klass(TestMetaclass.test_name(test_dir)))
        else: 
            parent_suite = new_suite

    with open('/autograder/results/results.json', 'w') as f:
        JSONTestRunner(visibility='visible', stream=f).run(suite)

    #with open('/autograder/results/results.json', 'r') as f:
    #    print(f.read())

    # could call post processor
    # check file presence and compilation
    with open('/autograder/results/results.json', 'r+') as f:
        data = json.load(f)
        compile_string = ''
        compile_score = 1
        for file in ['temperatures01', 'odds_evens01', 'temperatures02']:
            if os.path.exists('/autograder/submission/week10practice'):
                submission_path = '/autograder/submission/week10practice/'
            else:
                submission_path = '/autograder/submission/'

            print('searching for: ' + file)
            print(data['tests'])
            if not os.path.exists(submission_path + file + '.c'):
                compile_string = compile_string + "Missing file!!: " + file + '.c\n'
                compile_score = 0
                data['tests'] = [element for element in data['tests'] if not file in element['name']]
                
            if not os.path.exists(submission_path + file):
                compile_string = compile_string + "Could not compile!!: " + file + '.c\n\t Test results reported for this file are not meaningful.\n'
                compile_score = 0
                data['tests'] = [element for element in data['tests'] if not file in element['name']]
    
        data['tests'].insert(0, {"name": "File and Compilation Check", "max_score": 1, "score": compile_score, "output": compile_string})
        f.seek(0)
        f.truncate(0)
        json.dump(data, f, indent=4)

    with open('/autograder/results/results.json', 'r') as f:
        print(f.read())
