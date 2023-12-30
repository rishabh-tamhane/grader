# Grader

The Grader tool can be used to generate reports that includes statistics like percentile scores, histograms , section performance, individual performances across different subjects.

Here is the structure of the base code:

<pre>
.
├── .gitlab-ci.yml
└── hw2
    ├── .gitignore
    ├── hw2.sublime-project
    ├── include
    │   ├── allocate.h
    │   ├── debug.h
    │   ├── global.h
    │   ├── gradedb.h
    │   ├── normal.h
    │   ├── read.h
    │   ├── sort.h
    │   ├── stats.h
    │   ├── version.h
    │   └── write.h
    ├── Makefile
    ├── rsrc
    │   ├── cse307a.dat
    │   ├── cse307b.dat
    │   ├── cse307c.dat
    │   ├── cse307.collated
    │   ├── cse307.dat
    │   └── cse307.tabsep
    ├── src
    │   ├── allocate.c
    │   ├── error.c
    │   ├── main.c
    │   ├── normal.c
    │   ├── orig_main.c
    │   ├── read.c
    │   ├── report.c
    │   ├── sort.c
    │   ├── stats.c
    │   └── write.c
    ├── test_output
    │   └── .git-keep
    └── tests
        ├── basecode_tests.c
        ├── rsrc
        │   ├── blackbox_help.err
        │   ├── collate.in -> cse307.dat
        │   ├── collate.out
        │   ├── cse307a.dat
        │   ├── cse307b.dat
        │   ├── cse307c.dat
        │   ├── cse307.dat
        │   ├── tabsep.in -> cse307.dat
        │   └── tabsep.out
        ├── test_common.c
        └── test_common.h
</pre>

<pre>
Usage: bin/grades [options] <data file>
Valid options are:
	-r, --report                 	Process input data and produce specified reports.
	-c, --collate                	Collate input data and dump to standard output.
	    --freqs                  	Print frequency tables.
	    --quants                 	Print quantile information.
	    --summaries              	Print quantile summaries.
	    --stats                  	Print means and standard deviations.
	    --comps                  	Print students' composite scores.
	    --indivs                 	Print students' individual scores.
	    --histos                 	Print histograms of assignment scores.
	    --tabsep                 	Print tab-separated table of student scores.
	-a, --all                    	Print all reports.
	-k, --sortby     &lt;key&gt;          Sort by {name, id, score}.
	-n, --nonames                	Suppress printing of students' names.
</pre>

The `--reports` and `--collate` options are mutually exclusive positional arguments
that must appear first.  The remaining (non-positional) options may appear in any
order.  Following the options is a single final argument that specifies the name of
a data file to be read as input.

Option processing in `main()` is performed with the help of the GNU `getopt` library.
This library supports a flexible syntax for command-line arguments, including support
for traditional single-character options (prefixed by '-') and "long-form" options
(prefixed by '--'), which need not be single characters.
The library also takes care of some of the "grunt work" in parsing option arguments
and producing error messages.
You will probably need to read the Linux "man page" on the `getopt` package.
This can be accessed via the command `man 3 getopt`.  If you need further information,
search for "GNU getopt documentation" on the Web.
