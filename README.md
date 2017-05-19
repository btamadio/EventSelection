# RPV SUSY Event Selection code

This project implements the preselection for RPV SUSY analysis code

To run the preselection:

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

4. When jobs are complete, merege outputs
```bash
./Hadd_job.sh <job_name>
```