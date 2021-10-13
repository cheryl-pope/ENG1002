import unittest
import os
from gradescope_utils.autograder_utils.json_test_runner import JSONTestRunner
from test_generator import find_data_directories, build_test_class, TestMetaclass

if __name__ == '__main__':
    suite = unittest.TestSuite()
    parent_suite=suite
    # check for suites
    for root, dirs, files in os.walk('./test_data', topdown=true):
        new_suite = unittest.TestSuite();
        parent_suite.addTest(new_suite);

        # if we're in a bottom level
        if files:
            for name in files():
                klass = build_test_class(name)
                new_suite.addTest(klass(TestMetaclass.test_name(name)))
        parent_suite = new_suite

    with open('/autograder/results/results.json', 'w') as f:
        JSONTestRunner(visibility='visible', stream=f).run(suite)