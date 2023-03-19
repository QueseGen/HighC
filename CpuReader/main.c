//
//  main.c
//  HighC
//
//  Created by Jacquese Wilson on 3/19/23.
//

#include <stdio.h>
#include <sys/sysctl.h>

void _turbo(void);

int main(void) {
    // insert code here...
    printf("Hello, World!\n");
    _turbo();
    return 0;

}

void _turbo (void) {
    int mib[2];
    unsigned long long cpu_speed;
    size_t len = sizeof(cpu_speed);

    mib[0] = CTL_HW;
    mib[1] = HW_CPU_FREQ;
    sysctl(mib, 2, &cpu_speed, &len, NULL, 0);

    printf("CPU Speed: %llu GHz\n", cpu_speed / 1000000000);
}
