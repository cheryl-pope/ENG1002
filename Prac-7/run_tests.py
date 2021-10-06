import unittest
from gradescope_utils.autograder_utils.json_test_runner import JSONTestRunner
from gradescope_utils.autograder_utils.files import check_submitted_files
from test_generator import find_data_directories, build_test_class, TestMetaclass

missing_files = check_submitted_files(['odds_evens.c', 'process_ages.c', 'to_uppercase.c', 'to_uppercase2.c', 'reverse_in_place.c'])
for path in missing_files:
    print('Missing {0}'.format(path))
self.assertEqual(len(missing_files), 0, 'Missing some required files!')
print('All required files submitted!')

if __name__ == '__main__':
    suite = unittest.TestSuite()

    for name in find_data_directories():
        klass = build_test_class(name)
        suite.addTest(klass(TestMetaclass.test_name(name)))

    JSONTestRunner(visibility='visible').run(suite)
