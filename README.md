# RPV SUSY Event Selection code

This project implements the preselection for RPV SUSY analysis code

##To compile:
```bash
make
```

##To run the preselection:

1. Make a text file of ntuples to run over and put it in the files/ directory

2. Edit submit_event_selection/Submit_EventSelection.sh

```bash
source submit_selection.sh ${dir}/files/<input_file_list> job_name ${dir}
```

3. Run the script to submit jobs
```bash
cd submit_event_selection
./Submit_EventSelection.sh
```

4. When jobs are complete, merge outputs
```bash
./Hadd_job.sh <job_name>
```

Results end up in samples/<job_name>/main_<job_name>.root

For data, the GRL is selected automatically based on the job name. To use the 2015 GRL, the job name must contain "data2015" and to use the 2016 GRL, it must contain "data2016" This is case sensitive.

The GRL file paths are defined in src/eventSelection.cc. A relative path is currently defined, but has not been tested, so you may have to update the code to specificy the entire path where you have checked out the code.