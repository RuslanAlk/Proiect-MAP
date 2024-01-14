FROM gcc:latest
WORKDIR /usr/src/myapp
COPY regine.cpp .
RUN gcc -o regine regine.cpp -lstdc++
CMD ["./regine"]