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

 
   # with open('/autograder/results/results.json', 'r') as f:
   #     print(f.read())
