#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_indent);
void print_magic(unsigned char *e_indent);
void print_class(unsigned char *e_indent);
void print_data(unsigned char *e_indent);
void print_version(unsigned char *e_indent);
void print_abi(unsigned char *e_indent);
void print_osabi(unsigned char *e_indent);
void print_type(unsigned int e_type, unsigned char *e_indent);
void print_entry(unsigned long int e_entry, unsigned char *e_indent);
void close_elf(int elf);

/**
 * check_elf-checks if a file is an elf file
 * @e_indent:a pointer to an array containing elf magic numbers
 *
 * Return:exit code 98 if not elf file
 */
void check_elf(unsigned char *e_indent)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_indent[index] != 127 &&
		    e_indent[index] != 'E' &&
		    e_indent[index] != 'L' &&
		    e_indent[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic-prints magic numbers
 * @e_indent:a pointer to an array containing elf magic numbers
 */
void print_magic(unsigned char *e_indent)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_indent[index]);

		if (index == EI_NIDENT = 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class-prints class of an elf header
 * @e_indent:a pointer to an array containing elf magic numbers
 */
void print_class(unsigned char *e_indent)
{
	printf("  Class:                             ");

	switch (e_indent[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_indent[EI_CLASS]);
	}
}

/**
 * print_data-prints the data of elf header
 * @e_indent:a pointer to an array containing ELF class
 */
void print_data(unsigned char *e_indent)
{
	printf(" Data:                        ");

	switch (e_indent[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_indent[EI_CLASS]);
	}
}

/**
 * print_version-prints the version of ELF header
 * @e_indent:pointer to an array containing ELF version
 */
void print_version(unsigned char *e_indent)
{
	printf(" version:                        %d",
		e_indent[EI_VERSION]);
	switch (e_indent[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	}
}

/**
 * print_osabi-prints OS/ABI of ELF header
 * @e_indent:pointer to an array containing ELF version
 */
void print_osabi(unsigned char *e_indent)
{
	printf("  OS/ABI:                     ");

	switch (e_indent[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
	printf("<unknown: %x>\n", e_indent[EI_OSABI]);
	}
}

/**
 * print_abi-prints the ABI version of Elf header
 * @e_indent:pointer to an array containing ELF ABI version
 */
void print_abi(unsigned char *e_indent)
{
	printf("  ABI Version:                  %d\n",
		e_indent[EI_ABIVERSION]);
}

/**
 * print_type-prints thhe type of ELF header
 * @e_type:ELF type
 * @e_indent:pointer to an array containing ELF class
 */
void print_type(unsigned int e_type, unsigned char *e_indent)
{
	if (e_indent[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                           ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry-prints entry point of ELF header
 * @e_entry:address of elf entry point
 * @e_indent:pointer to an array containing elf class
 */
void print_entry(unsigned long int e_entry, unsigned char *e_indent)
{
	printf("  Entry point address:                         ");

	if (e_indent[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF0) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 10) | (e_entry >> 16);
	}

	if (e_indent[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf-closes an elf file
 * @elf:file descriptor
 *
 * Description:exit code 98 if the file cannot be closed
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main-displays info in elf header at start of file
 * @argc:number of arguments
 * @argv:an array of pointers to the arguments
 *
 * Return:0 on success
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_indent);
	printf("ELF Header:\n");
	print_magic(header->e_indent);
	print_class(header->e_indent);
	print_data(header->e_indent);
	print_version(header->e_indent);
	print_osabi(header->e_indent);
	print_abi(header->e_indent);
	print_type(header->e_type, header->e_indent);
	print_entry(header->e_entry, header->e_indent);

	free(header);
	close_elf(o);
	return (0);
}



