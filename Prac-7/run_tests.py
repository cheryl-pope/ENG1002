import unittest
from gradescope_utils.autograder_utils.json_test_runner import JSONTestRunner
from gradescope_utils.autograder_utils.files import check_submitted_files
from test_generator import find_data_directories, build_test_class, TestMetaclass

if __name__ == '__main__':
    suite = unittest.TestSuite()

    for name in find_data_directories():
        klass = build_test_class(name)
        suite.addTest(klass(TestMetaclass.test_name(name)))

    JSONTestRunner(visibility='visible').run(suite)

missing_files = check_submitted_files(['odds_evens.c', 'process_ages.c', 'to_uppercase.c', 'to_uppercase2.c', 'reverse_in_place.c'])
file_check = {
        "name": "Checking submitted files",
        "visibility": "visible"
}
if (len(missing_files) == 0)
    filecheck.update({"output": "All code files submitted!"})
else
    missing_string = "Missing some code files!\n"
    for path in missing_files:
        missing_string = missing_string + "\n" + 'Missing {0}'.format(path)
    file_check.update({"output": missing_string}

print(file_check)

file = open('results.json',)
json_data = json.load(file)
json_data['tests'].append(file_check)

print(json_data)

file.seek(0)
json.dump(json_data, file)
file.close()
