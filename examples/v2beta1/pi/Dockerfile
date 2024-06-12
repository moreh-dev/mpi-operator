# docker build --build-arg BASE_LABEL=latest -t harbor.moreh.dev/pcs-test/mpi-pi:0213 . && docker push harbor.moreh.dev/pcs-test/mpi-pi:0213

ARG BASE_LABEL

FROM mpioperator/openmpi-builder:${BASE_LABEL} as builder

COPY pi.cc /src/pi.cc
RUN mpic++ /src/pi.cc -o /pi

FROM mpioperator/openmpi:${BASE_LABEL}

COPY --from=builder /pi /home/mpiuser/pi
