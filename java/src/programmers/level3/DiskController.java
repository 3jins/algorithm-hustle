package programmers.level3;

import java.util.PriorityQueue;

public class DiskController {
    private class Job {
        int startTime;
        int duration;

        public Job(int startTime, int duration) {
            this.startTime = startTime;
            this.duration = duration;
        }

        @Override
        public String toString() {
            return "Job{" +
                    "startTime=" + startTime +
                    ", duration=" + duration +
                    '}';
        }
    }

    private class JobByStartTime extends Job implements Comparable<Job> {
        public JobByStartTime(int startTime, int duration) {
            super(startTime, duration);
        }

        @Override
        public int compareTo(Job job) {
            if (this.startTime == job.startTime) {
                return this.duration >= job.duration ? 1 : -1;
            }
            return this.startTime >= job.startTime ? 1 : -1; // min heap
        }
    }

    private class JobByDuration extends Job implements Comparable<Job> {
        public JobByDuration(int startTime, int duration) {
            super(startTime, duration);
        }

        @Override
        public int compareTo(Job job) {
            if(this.duration == job.duration) {
                return this.startTime >= job.startTime ? 1 : -1;
            }
            return this.duration >= job.duration ? 1 : -1; // min heap
        }
    }

    public int solution(int[][] jobs) {
        int total = 0;

        PriorityQueue<JobByStartTime> jobsByStartTime = new PriorityQueue<>();
        PriorityQueue<JobByDuration> jobsByDuration = new PriorityQueue<>();
        for (int[] job : jobs) {
            jobsByStartTime.add(new JobByStartTime(job[0], job[1]));
        }

        Job currentJob = null;
        int endTime = 0;
        while (true) {
            if (jobsByStartTime.isEmpty()) { // 남은 작업이 업음.
                if (jobsByDuration.isEmpty()) { // 큐에도 남은 게 없음. 끝.
                    break;
                } else { // 큐에 남은 애들 소요시간 순서대로 처리.
                    Job nextJob = jobsByDuration.poll();
                    total += Math.max(endTime, nextJob.startTime) - nextJob.startTime + nextJob.duration;
                    endTime += nextJob.duration;
                    currentJob = nextJob;
                    continue;
                }
            }
            Job newJob = jobsByStartTime.peek();
            if ((currentJob == null || newJob.startTime >= endTime)) { // 현재 처리 중인 task가 없거나 끝났음
                if (jobsByDuration.isEmpty()) {
                    // 큐에 넣어놨던 게 없음. 그냥 얘부터 바로 처리.
                    currentJob = newJob;
                    total += currentJob.duration;
                    endTime = currentJob.startTime + currentJob.duration;
                    jobsByStartTime.poll();
                } else {
                    // 큐에 넣어놨던 거 소요시간 순서대로 처리.
                    Job nextJob = jobsByDuration.poll();
                    total += Math.max(endTime, nextJob.startTime) - nextJob.startTime + nextJob.duration;
                    endTime += nextJob.duration;
                    currentJob = nextJob;
                }
            } else {
                // 현재 처리 중인 task가 끝나지 않았으므로, 큐에 저장해뒀다가 짧은 순으로 꺼내 처리할 예정.
                jobsByDuration.add(new JobByDuration(newJob.startTime, newJob.duration));
                jobsByStartTime.poll();
            }
        }

        return total / jobs.length;
    }
}
