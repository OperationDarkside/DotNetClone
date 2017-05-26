#pragma once

#ifndef NETWORKSTREAM_H
#define NETWORKSTREAM_H

#include "String.h"
#include "Socket.h"

namespace dnc{
	namespace Net{
		namespace Sockets{

			class NetworkStream: public Object{
			public:
				NetworkStream(Socket socket);
				~NetworkStream();

				std::string ToString() override;
				std::string GetTypeString() override;

				void Close();
				bool DataAvailable();
				Socket GetSocket();
				template<size_t num>
				int Read(std::array<unsigned char, num> buffer, int offset, int size);
				unsigned char ReadByte();
				template<size_t num>
				int Write(std::array<unsigned char, num> buffer, int offset, int size);
				void WriteByte(unsigned char value);

			private:
				Socket sock;
			};

			template<size_t num>
			inline int NetworkStream::Read(std::array<unsigned char, num> buffer, int offset, int size){
				return this->sock.Receive(buffer, offset, size);
			}
			template<size_t num>
			inline int NetworkStream::Write(std::array<unsigned char, num> buffer, int offset, int size){
				return this->sock.Send(buffer, offset, size);
			}
		}
	}
}
#endif
